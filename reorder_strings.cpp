#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <omp.h>
#include <chrono>

//Globals:

//constexpr int NUM_CORES = 16; //change this value as needed

//origionally defined the number of cores directly at top of file as global var, now we are running the program several times and determining # of cores at runtime based on each run in the malefile  

void reverseString(std::string& str) {
    std::reverse(str.begin(), str.end());
}


int main() {
   const char* env_var = std::getenv("OMP_NUM_THREADS");
   int num_threads = (env_var != nullptr) ? std::stoi(env_var) : 1; 
   omp_set_num_threads(num_threads);
   //auto start_time = std::chrono::high_resolution_clock::now(); //get start time value 
   int NUM_THREADS = num_threads; 
   int NUM_CORES =  omp_get_num_procs();
   std::cout << "running with" << NUM_THREADS << "on" << NUM_CORES << std::endl; 

   std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "error: Unable to open input.txt" << std::endl;
        return 1;
    }
    ///define vector to store lines from input & read lines from input file
    std::vector<std::string> lines;
    std::string line;
       while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    std::cout << "Number of lines in the file: " << lines.size() << std::endl; //sanity check #of lines in input file (input.txtd)
 
    // Get number of CPU cores
    

    
    auto start_time = std::chrono::high_resolution_clock::now(); //get start time value 
    // OpenMP parallelization
    #pragma omp parallel for shared(lines)
    for (int i = 0; i < lines.size(); ++i) {
        reverseString(lines[i]);
    }
    
    auto end_time = std::chrono::high_resolution_clock::now(); // Measure end time
    //auto end_time = std::chrono::steady_clock::now(); // Measure end time
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count(); // Calculate elapsed time
    
   // Open output text file
    // if file does not exist, it will be created, else overwritten
    std::ofstream outputTextFile("output.txt");
    if (!outputTextFile) {
        std::cerr << "error: Unable to open output.txt" << std::endl;
        return 1;
    }
    for (const auto& line : lines) {
        outputTextFile << line << std::endl;
    }
    outputTextFile.close();

    // Open output CSV file
    // if file does not exist, it will be created, else overwritten
    std::ofstream outputCSVFile("output_" + std::to_string(NUM_THREADS) + "cores.csv");
    if (!outputCSVFile) {
        std::cerr << "error: Unable to open output.csv" << std::endl;
        return 1;
    }
    // Write CSV header  // Write result to CSV file
    outputCSVFile << "NumLines,NumCores,ExecutionTime(ms)" << std::endl;
    outputCSVFile << lines.size() << "," << NUM_THREADS << "," << elapsed_time << std::endl;
    outputCSVFile.close();

    std::cout << "Reversal completed successfully." << std::endl;
    std::cout << "Runtime complexity: " << elapsed_time << " milliseconds" << std::endl;

    return 0;
}

