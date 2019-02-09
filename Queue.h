//
// Original is copyrighted, source avaliable to instructors on request
// Modifications by M. Molodowitch


// Template Queue class definition
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cassert>
#include "Node.h"

using std::cout;
using std::ostream;

template< class NODETYPE >
class Queue {
public:
   Queue();      // constructor
   ~Queue();     // destructor
   bool enqueue( const NODETYPE & );
   bool dequeue( NODETYPE & );
   bool isEmpty() const;
   bool isFull() const;

private:
   Node< NODETYPE > *queuePtr;  // pointer to first node
   Node< NODETYPE > *rearPtr;  // pointer to first node
   // Utility function to allocate a new node
   Node< NODETYPE > *getNewNode( const NODETYPE & );
};

// Default constructor
template< class NODETYPE >
Queue< NODETYPE >::Queue() : queuePtr( 0 ), rearPtr( 0) { }

// Destructor
template< class NODETYPE >
Queue< NODETYPE >::~Queue()
{
   if ( !isEmpty() ) {    // Queue is not empty
      cout << "Destroying nodes ...\n";

      Node< NODETYPE > *tempPtr;

      while ( queuePtr != 0 ) {  // delete remaining nodes
         tempPtr = queuePtr;
         cout << tempPtr->data << '\n';
         queuePtr = queuePtr->nextPtr;
         delete tempPtr;
      }

	  rearPtr = 0;
   }

   cout << "All nodes destroyed\n\n";
}

// Insert a node at the front of the Queue
template< class NODETYPE >
bool Queue< NODETYPE >::enqueue( const NODETYPE &value )
{
   Node< NODETYPE > *newPtr = getNewNode( value );

   if (newPtr == 0)		//failure to allocate new node
	   return false;
   else {

	  if ( rearPtr == 0 )   // Queue is empty
         queuePtr = newPtr;
	  else
		 rearPtr->nextPtr = newPtr; // Queue is not empty

	  rearPtr = newPtr;
      
	  return true;		// enqueue is successful
   }
}

// Delete a node from the front of the list
template< class NODETYPE >
bool Queue< NODETYPE >::dequeue( NODETYPE &value )
{
   if ( isEmpty() )             // List is empty
      return false;             // delete unsuccessful
   else {
      Node< NODETYPE > *tempPtr = queuePtr;

      queuePtr = queuePtr->nextPtr;

      value = tempPtr->data;  // data being removed

	  if (queuePtr == 0)
		  rearPtr = 0;

      delete tempPtr;
      return true;            // delete is successful
   }
}


// Is the Queue empty?
template< class NODETYPE > 
bool Queue< NODETYPE >::isEmpty() const
	{ return (queuePtr == 0); }

// Is the Queue full?
template< class NODETYPE > 
bool Queue< NODETYPE >::isFull() const 
{
	Node< NODETYPE > *newPtr = new Node< NODETYPE >;

   if (newPtr == 0)		//failure to allocate new node
	   return true;

   else {
	   delete newPtr;
	   return false;
   }
}


// Return a pointer to a newly allocated node
template< class NODETYPE >
Node< NODETYPE > *Queue< NODETYPE >::getNewNode( 
                                        const NODETYPE &value )
{
   Node< NODETYPE > *ptr = new Node< NODETYPE >( value );
   assert( ptr != 0 );
   return ptr;
}



#endif


