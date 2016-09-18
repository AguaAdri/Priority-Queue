#ifndef PCB_H
#define PCB_H

#include <iostream>
using namespace std;

class PCB
{
 private:
  int iD;
  int priority;
  string state;
  int position; // Stores object's position in the vector
 public:
  PCB();
  PCB(int);
  void setPriority(int);
  void decrement(); //decrements priority to a minimum of 1;
  void changeToReady();
  void changeToRunning();
  int getId();
  int getPriority();
  string getState();
};

#endif
