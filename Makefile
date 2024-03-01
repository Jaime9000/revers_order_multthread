CC = g++-13
CFLAGS = -std=c++17 -Wall -Wextra -fopenmp
LDFLAGS = -fopenmp
SRC = reorder_strings.cpp
EXEC = reorder_strings

# List of core counts to test
CORES = 2 4 6 8 10 12 14 16

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

run: $(EXEC)
	@for core in $(CORES); do \
		OMP_NUM_THREADS=$$core ./$(EXEC); \
	done

clean:
	rm -f $(EXEC) output.txt output_*.csv


