#include "PCBTable.h"

PCBTable::PCBTable()
{
  srand(time(NULL));
}

/* Initializes the PCBTable to have 'size' amount of PCB objects. */
void PCBTable::initializeTable(int size)
{
  for(int i = 0;i < size; i++)
    {
      PCB newPCB(i);
      addElement(newPCB);
    }
}

void PCBTable::addElement(PCB element)
{
  elementTable.push_back(element);
}

/* Grabs PCB from position pos in the vector only after checking if it isn't in the queue already. */
PCB PCBTable::getElement(int pos)
{
  if(isValid(elementTable[pos])) //Makes sure the PCB isn't in the queue
    {
      elementTable[pos].changeToReady();
      PCB elem = elementTable[pos];
      return elem;
    }
  else
    return 0;
}

/* Gets a random PCB from the PCBTable and initializes it with a random priority. */
PCB PCBTable::getRandomPriority()
{
  int elementPos = rand()%20;
  int elementPri = rand()%50 + 1;
  int count = 0;
  while(count == 0)
    {
      if(isValid(elementTable[elementPos]))
	{
	  elementTable[elementPos].changeToReady(); //Changes elements state in the table
	  PCB element = elementTable[elementPos];
	  element.setPriority(elementPri);
	  count = 1;
	  return element;
	}
      elementPos = rand()%20;
    }
}

/* Returns true if element isn't in the queue. It checks this by looking at its state. If it is "READY" it is in the queue. */
bool PCBTable::isValid(PCB element)
{
  if(element.getState() != "READY")
    return true;
  else
    return false;
}

void PCBTable::runningState(int pos)
{
  elementTable[pos-1].changeToRunning();
}

void PCBTable::displayTable()
{
  for(int i = 0;i < elementTable.size(); i++)
    cout << elementTable[i].getId() << " State: " << elementTable[i].getState() << " Priority; " << elementTable[i].getPriority() << endl;
  cout << endl;
}

void PCBTable::test()
{
  for(int i = 0;i < elementTable.size(); i++)
    elementTable[i].decrement();
}
