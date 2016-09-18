#include "PCB.h"
PCB::PCB()
{
}

PCB::PCB(int idNum)
{

  iD = idNum + 1;
  priority = idNum + 1;
  state = "NEW";
  position = idNum;
}

void PCB:: setPriority(int prty)
{
  priority = prty;
}

void PCB::decrement()
{
  if(priority - 1 < 1)
    return;
  else
    priority--;
}

void PCB::changeToReady()
{
  state = "READY";
}

void PCB::changeToRunning()
{
  state = "RUNNING";
}

int PCB::getId()
{
  return iD;
}

int PCB::getPriority()
{
  return priority;
}

string PCB::getState()
{
  return state;
}
