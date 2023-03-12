//------------------------------------------------------------------------------
// IntQueue.h : class declaration/specification
//------------------------------------------------------------------------------
#ifndef INTQUEUE_H
#define INTQUEUE_H

//------------------------------------------------------------------------------
// IntQueue
//------------------------------------------------------------------------------
class IntQueue {
private:
   int *queueArray;  // Points to the queue array
   int queueSize;    // The queue size
   int front;        // Subscript of the queue front
   int rear;         // Subscript of the queue rear
   int numItems;     // Number of items in the queue

public:
   // constructor
   IntQueue(int);
   
   // copy constructor
   IntQueue(const IntQueue &);
   
   // destructor
   ~IntQueue();

   // queue operations
   void enqueue(int);
   void dequeue(int &);
   bool isEmpty() const;
   bool isFull() const;
   void clear();
};
#endif