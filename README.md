Task: 'You have a text file with a lot of strings - input.txt. You need to reverse order of characters in each line from input.txt. And then write resulted lines to output.txt. Order of lines in output.txt can be different from input.txt. Please use several threads to achieve that and perform transformation of the file faster.'












**Please note: 

--> I have generated the input.txt file via a small python script that is attached, this allowed me to test the c++ with different inputs adhering to the same conditions 

-->I have done my testing with a txt file of 1000000 lines, I found that this would better reflect the actual time saved via the multi-threading process likely due to the fact that the library used for calculating the differences in times is probably not the most accurate (I used crono lib, although I did try and increase accuracy by specifying the high-resolution param). 

-->I have included output.txt as well as the results of a 2/4/8 thread runs of the program which are saved to their respective csv files. (I chose csv because if I was considering consolidating this data for visual representation via graphing purposes on a grafana dashboard). 

--> If you attempt to run the program with different inputs which is advisable as it will print the number of cores and threads used in real-time which you can specify with 'export OMP_NUM_THREADS=x' and then running the solution with './reorder_strings' I would avoid using the makefile at this time because I was experimenting getting it to return output from several different runs with different threads and consolidating all into a single csv and its still buggy at the moment. 
