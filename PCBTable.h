#ifndef PCBTABLE_H
#define PCBTABLE_H

#include "PCB.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

class PCBTable
{
 private:
  vector<PCB> elementTable;
 public:
  PCBTable();
  void addElement(PCB); //Inserts a PCB instance to the vector
  void initializeTable(int); //Creates a vector with an assigned number of PCB objects. The priority == id
  PCB getElement(int); // Grabs element at position that is passed in
  PCB getRandomPriority(); //Gets an element from a table with a random priority 
  bool isValid(PCB);
  void runningState(int);
  void displayTable();
  void test();
};

#endif
