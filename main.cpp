//NAMES:       Adrian Aguayo, Richard Casillas
//DATE:        17 SEP 2016
//COURSE:      CS433 Operating Systems
//ASSIGNMENT:  #1 (Priority Queue of Processes)
//DESCRIPTION: This program will implement a process control block in order to manage a priority queue of processes.
//             It utilizes a PCB(process control block) object which has a state, ID, Priority, and a position. These PBC 
//             objects are stored in a vector of PBC's. A ready queue is then implemented through the use of an ordered 
//             binary search tree. The PBC objects are then copied from the PBC table into the ready queue(binary search tree). 
//             Objects with the highest priority are always removed from the ready queue first and new PBC's are added to
//             the tree in their correct locations. 
#include "PCB.h"
#include "PCBTable.h"
#include "readyQueue.h"
#include <ctime>

void test1(PCBTable);
void test2(PCBTable);

int main()
{
  PCBTable table;
  table.initializeTable(20);
  test1(table);
  test2(table);
  return 0;
}

void test1(PCBTable table)
{
  cout << "Test 1:" << endl << endl;
  BST tree;
  PCB temp = table.getElement(4);
  tree.insertProc(temp);
  temp = table.getElement(0);
  tree.insertProc(temp);
  temp = table.getElement(7);
  tree.insertProc(temp);
  temp = table.getElement(10);
  tree.insertProc(temp);
  tree.displayQueue();

  temp = tree.removeHighestProc();
  table.runningState(temp.getId());
  tree.displayQueue();

  temp = tree.removeHighestProc();
  table.runningState(temp.getId());
  tree.displayQueue();

  temp = table.getElement(2);
  tree.insertProc(temp); 
  temp = table.getElement(6);
  tree.insertProc(temp); 
  temp = table.getElement(1);
  tree.insertProc(temp); 
  temp = table.getElement(11);
  tree.insertProc(temp); 
  temp = table.getElement(8);
  tree.insertProc(temp); 
  tree.displayQueue();

  int size = tree.getSize();
  for(int i = 0;i < size; i++)
    {
      temp = tree.removeHighestProc();
      table.runningState(temp.getId());
      tree.displayQueue();
    }
}

void test2(PCBTable table)
{
  clock_t start,end; // Will store time to evaluate how long it took to go through the loop
  cout << "Test 2:"<< endl << endl;
  PCB temp;
  BST tree;
  for(int i = 0; i < 10; i++) // Adds 10 random PCBs onto the tree with random priorities
    {
      temp = table.getRandomPriority();
      tree.insertProc(temp);
    }
  tree.displayQueue();
  start = clock();
  for(int i = 0; i <1000000;i++)
    {
      temp = tree.removeHighestProc();
      table.runningState(temp.getId());
      tree.alterPriority();
      temp = table.getRandomPriority();
      tree.insertProc(temp);
    }
  end = clock();
  tree.displayQueue();
  cout<< "The process took " << (double(end-start)/CLOCKS_PER_SEC) << " seconds." << endl;
}
