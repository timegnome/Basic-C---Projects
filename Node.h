// Original source attribution available
// Modified by M. Molodowitch

// Node template definition: each Node object contains data and a pointer to the following node.
// For use in linked lists and in linked list implementations of a stack and a queue.

#ifndef NODE_H
#define NODE_H

template< class NODETYPE > class Stack;  // forward declarations
template< class NODETYPE > class Queue;

template<class NODETYPE>
class Node {
   friend class Stack< NODETYPE >; // make Stack a friend
   friend class Queue< NODETYPE >; // make Queue a friend
public:
   Node( const NODETYPE & );  // constructor
   Node();
   NODETYPE getData() const;      // return data in the node
private:
   NODETYPE data;                 // data
   Node< NODETYPE > *nextPtr; // pointer to the next node in the list
};

// Constructor
template<class NODETYPE>
Node< NODETYPE >::Node( const NODETYPE &info )
   : data( info ), nextPtr( 0 ) { }

template<class NODETYPE>
Node< NODETYPE >::Node( )
   : nextPtr( 0 ) { }


// Return a copy of the data in the node
template< class NODETYPE >
NODETYPE Node< NODETYPE >::getData() const { return data; }

#endif


