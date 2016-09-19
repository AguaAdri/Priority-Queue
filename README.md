# Priority-Queue

NAMES:       Adrian Aguayo, Richard Casillas

DATE:        17 SEP 2016

COURSE:      CS433 Operating Systems

ASSIGNMENT:  #1 (Priority Queue of Processes)

COMPILATION: In order to compile the program through UNIX, navigate to the desired directory with the program files.
             In the command prompt enter: make 
             
             This will compile, optimize, and create an executable file named: executable
             To run the program enter: ./executable

DESCRIPTION: This program will implement a process control block in order to manage a priority queue of processes.
             It utilizes a PCB(process control block) object which has a state, ID, Priority, and a position. These PBC 
             objects are stored in a vector of PBC's. A ready queue is then implemented through the use of an ordered 
             binary search tree. The PBC objects are then copied from the PBC table into the ready queue(binary search tree). 
             Objects with the highest priority are always removed from the ready queue first and new PBC's are added to
             the tree in their correct locations. 
             
DESIGN CHOICES: We chose to implement the PBC table using a vecor. The reason for this choice was because we wanted to 
                allow flexibility/usability for possible future needs of different clients. A vector allows us to implement
                an array of pointers on the stack to the memory locations of each PBC in the heap(main memory). If a future user
                calls for a PCB with additional variables or PBC's this can be easily changed without taking up unneccesary space on the stack.
                As for the ready queue, we chose to implement it using an ordered binary search tree. The reason for this design choice is due to the ordered binary search trees advanced time complexity. On average, the traversal of the tree during each comparison during insertion, lookup, and deletion can be accomplished in O(Log n) operations where 'n' is the number of items in the tree. In a worst case scenario, all priorities in the tree could be the same in which case the scenario would take 'n' operations where 'n' is the number of elements in the tree. Since we were using randomized priorities for test two,the chances of a linear search happening are slim. 
                Also, we chose to delete to loweest level of a given priority rather than the first PCB of that priority added to the tree. This choice was due to the fact that through randomization, there was only a 1 in 50 chance that there would be 2 PCB's with the same priority and even less after you consider only 10 of those PCB's are in the tree at any given time.

RUN TIME: After running our program 15 times the average time spent on the 1,000,000 iterations in test 2 was an astonishing 1.45
          seconds. This speed was expected since the binary search tree is structured to handle large sets of data in O(lon n) time.
