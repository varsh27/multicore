Manual for testing Parallel Data structure library.

Steps to compile and run:

Load latest gcc version   (module load gcc-8.2)
Compile test.cpp file     (g++ -o createTest test.cpp)
Run executable            (./createTest <data-struture> <number-of-operations>)
Run makefile              (make)
Run simulator executable  (./simulator <test-file-name> <number-of-threads>)

Valid characters for <data-struture>: d OR s OR a

q - Creates test case for Dequeue
d - Creates test case for Doubly Linked List
s - Creates test case for Stacks
l - Creates test case for Singly Linked List
a - Creates test case for Arrays

Valid <number-of-operations> values: Positive integers
Valid <number-of-threads> values: Positive integers
Valid <test-file-name> values: Name of the test file created



Example steps to check dequeue data-struture with 1000 operations, 1 thread:

module load gcc-8.2
g++ -o createTest test.cpp
./createTest q 1000
make
./simulator test_dequeue_1000.txt 1



Example steps to check stack data-struture with 4000 operations, 8 thread:

module load gcc-8.2
g++ -o createTest test.cpp
./createTest s 4000
make
./simulator test_dequeue_4000.txt 8



Example steps to check doubly-linked list data-struture with 10000 operations, 10 thread:

module load gcc-8.2
g++ -o createTest test.cpp
./createTest d 10000
make
./simulator test_dequeue_10000.txt 10


