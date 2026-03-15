//------------------------------------------------------------------------------
// IntQueue.cpp : class definition/implementation
//------------------------------------------------------------------------------
#include "IntQueue.h"

#include <iostream>

//------------------------------------------------------------------------------
// constructor : creates an empty queue of specified size
//------------------------------------------------------------------------------
IntQueue::IntQueue(int size)
{
    queueArray = new int[size];
    queueSize = size;
    front = -1;
    rear = -1;
    numItems = 0;
}

//------------------------------------------------------------------------------
// copy constructor
//------------------------------------------------------------------------------
IntQueue::IntQueue(const IntQueue& rhs)
{
    // allocate the new queue array
    queueArray = new int[rhs.queueSize];

    // copy the old queue's attributes to the new queue
    queueSize = rhs.queueSize;
    front = rhs.front;
    rear = rhs.rear;
    numItems = rhs.numItems;

    // copy the old queue's data
    for (int count = 0; count < rhs.queueSize; count++)
        queueArray[count] = rhs.queueArray[count];
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
IntQueue::~IntQueue() { delete[] queueArray; }

//------------------------------------------------------------------------------
// inserts a value at the rear (tail) of the queue
//------------------------------------------------------------------------------
void IntQueue::enqueue(int value)
{
    if (isFull())
        std::cout << "The queue is full.\n";

    else {
        // calculate the new tail position
        rear = (rear + 1) % queueSize;

        // insert new item
        queueArray[rear] = value;

        // update item count
        numItems++;
    }
}

//------------------------------------------------------------------------------
// removes the value at the front of the queue and copies it into value
//------------------------------------------------------------------------------
void IntQueue::dequeue(int& value) 
{
    if (isEmpty()) 
    {
        std::cout << "The queue is empty.\n";
        return;
    }

    // move front
    front = (front + 1) % queueSize;

    // retrieve the front item
    value = queueArray[front];

    // update item count
    numItems--;
}

//------------------------------------------------------------------------------
// returns true if the queue is empty, false otherwise
//------------------------------------------------------------------------------
bool IntQueue::isEmpty() const { return numItems ? false : true; }

//------------------------------------------------------------------------------
// returns true if the queue is full, false otherwise
//------------------------------------------------------------------------------
bool IntQueue::isFull() const { return numItems < queueSize ? false : true; }

//------------------------------------------------------------------------------
// - sets the front and rear indices
// - sets numItems to 0
//------------------------------------------------------------------------------
void IntQueue::clear() 
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}