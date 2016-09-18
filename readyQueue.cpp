using namespace std;

#include <iostream>
#include "readyQueue.h"

// constructor  initializes Root
BST::BST()
{
   Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
   dtraverse(Root); // traverse to delete all vertices in post order
   Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  
{   
  if (V != NULL) 
    {
      dtraverse(V->Left);
      dtraverse(V->Right);       
      delete V;                  
    }
}


// PURPOSE: Show elements in IN order traversal knowing the Root
void BST::displayQueue()
{
  cout << "Ready Queue:" << endl;
  if(Root == NULL)
    {   
      cout <<"EMPTY QUEUE" << endl;
      return;
    }
  INorderTraversal(Root);
  cout << endl;
}

// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
    if (V != NULL)
      {
        INorderTraversal(V->Left); 
        cout<< "ID: " << V->Elem.getId() << " "; 
	cout << "Priority: " << V-> Elem.getPriority() << " " << endl;

	INorderTraversal(V->Right);
      }
}

// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: Traverses tree iteratively to insert new PBC  
//    - smaller priority than the current -> go to the left
//    - bigger priority than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::insertProc(elem_t E)
{
  
   Vertex *N;         
   N = new Vertex;    
   N->Left  = NULL; 
   N->Right = NULL;         
   N->Elem  = E;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;       
     }
   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
	Vertex *Parent;
        V = Root;        
        
	while (V != NULL)  // go down the tree until you cannot go any further
	  {
	    if (N->Elem.getPriority() <= V->Elem.getPriority())  // what I have is smaller  or equal to  V
	      {  
		Parent= V; 
		V= V->Left; 
	      }
	    else // what I have is bigger than V
	      {  
		Parent= V; 
		V= V->Right;  
	      }
	    
	  }        
        // reached NULL -- Must add N as the Parent's child
     
	if (N->Elem.getPriority() <= Parent->Elem.getPriority()) // case where new priority is less than or equal to parent
	    Parent->Left=N;
	else //what i have is greater than the parent
	    Parent->Right=N;

     }
   SIZE++;
}

// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  if((V->Left==NULL)&&(V->Right==NULL))// if V is a leaf (case 1)
    {
      if(V==P->Left)//  if V is a left child of P
	{
	  delete V;
	  P->Left=NULL; 
	}
      else // V is a right child of the Parent
	{ 
	  delete V;
	  P->Right=NULL; 
	}
    }
  
  else 
    if((V->Right==NULL) && (V->Left!=NULL))// if V has just the left child (case 2)
      {
	if(V->Elem.getPriority() <= P->Elem.getPriority())
	  P->Left= V->Left;
	else
	  P->Right=V->Left;
	delete V;
      }       
  
    else
      if((V->Right!=NULL) && (V->Left==NULL))//if V has just the right child
	{
	  if(V->Elem.getPriority() <= P->Elem.getPriority())
	    P->Left = V->Right;
	  else
	    P->Right=V->Right;
	  delete V;
        }
     
      else // V has two children (case 3)
	{
	  elem_t Melem;
          Melem = findMax(V); // find MAX element in the left sub-tree of V
          V->Elem = Melem;
        }
}

// PURPOSE: Finds the Maximum element in the left sub-tree of V to replace V
elem_t BST::findMax(Vertex *V)
{
     Vertex *Parent = V;
     V = V->Left;          

     while(V->Right!=NULL)//While the right child of V is still available
       {
	 Parent=V;
	 V=V->Right;
       }

    // reached NULL Right  -- V now has the MAX element
     elem_t X = V->Elem;
     remove(V, Parent);     
     return X;             

}
//PURPOSE: To search through the tree for the highest priority PCB
elem_t BST::removeHighestProc()
{
  Vertex *V = Root;
  Vertex *Parent = V;
  if (V->Left != NULL)//Root has left children
    V = V->Left;
  else if((Parent->Left == NULL) && (Parent->Right != NULL)){//Root has no left children
    V = V->Right;
    elem_t temp = Parent->Elem;
    Root = V;
    delete Parent;
    SIZE--;
    return temp;
  } 
  else if((Parent->Left == NULL) && (Parent->Right == NULL)){//Root has no children
    elem_t temp = Parent->Elem;
    delete Parent;
    Root = NULL;
    SIZE--;
    return temp;
  }
  while(V->Left != NULL){//Traverse left side of tree
    Parent = V;
    V=V->Left;
  }
  elem_t temp = V->Elem;//Store PBC object being deleted to pass back to main. 
  remove(V, Parent);
  SIZE--;
  return temp;
}

//PURPOSE:Passes the pointer to the root PCB to decrementPriority
void BST::alterPriority(){
   decrementPriority(Root);
}

//PURPOSE: Traverses the tree recursivly and decrements each priority
//PARAM: Pointer to the root vertex
void BST::decrementPriority(Vertex *V){
   if (V != NULL)
     {
       decrementPriority(V->Left); 
       V->Elem.decrement();
       decrementPriority(V->Right);

     }
 }
//PURPOSE: To return the current number of vertex's in the tree.
int BST::getSize(){
  return SIZE;
}
