#ifndef READYQUEUE_H
#define READYQUEUE_H

#include "PCB.h"

typedef PCB elem_t;   // elem_t is hidden from the client


// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Left;
  elem_t Elem;
  Vertex *Right;
};   


class BST
{

 private:
  Vertex *Root;  // data member is Root which is a pointer to the root vertex
  int SIZE = 0;  //variable used to keep track of # of nodes in the binary search tree
 public:
  
  BST();
  ~BST();  // destructor calls dtraverse to destroy the dynamic tree

  int getSize(); //returns the size of the queue

  // PURPOSE: this will show the vertices in IN order. Provides the root vertex pointer to the INorderTraversal function. 
  void displayQueue();      

  // PURPOSE: This inserts a new vertex into the BST 
  //  provides the element to be inserted into the tree
  void insertProc(elem_t);
  
  //PURPOSE: searches for the highest priority node in the tree. 
  //Passes pointer to this node to the remove function to be removed.
  elem_t removeHighestProc(); 

  // PURPOSE: passes the root node to decrement Priority which traverses the tree until
  //all priorities have been decremented
  void alterPriority();  
 
 protected: 
  // These were created to implement the public methods without giving client access to unneccesary information

  //PURPOSE: traverse and delete all vertices in post order called in the destructor.
  void dtraverse(Vertex*);

  //PURPOSE: Removes the vertex knowing its parent
  void remove(Vertex*, Vertex*);

  //PURPOSE: finds the max element in the left sub tree to replace a parent node being deleted
  elem_t findMax(Vertex*);  
  
  //PURPOSE: Decrements the priority of all nodes knowing the root node
  void decrementPriority(Vertex*);

  //PURPOSE: Traverses the binary search tree in order to display the current order of the queue.
  void INorderTraversal(Vertex*);


};

#endif
