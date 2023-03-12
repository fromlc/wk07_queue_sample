//------------------------------------------------------------------------------
// IntQueue.cpp : class definition/implementation
//------------------------------------------------------------------------------
#include "IntQueue.h"

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// constructor : creates an empty queue of specified size
//------------------------------------------------------------------------------
IntQueue::IntQueue(int s) {
    queueArray = new int[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

//------------------------------------------------------------------------------
// copy constructor
//------------------------------------------------------------------------------
IntQueue::IntQueue(const IntQueue& obj) {

    // allocate the new queue array
    queueArray = new int[obj.queueSize];

    // copy the old queue's attributes to the new queue
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    // copy the old queue's data
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
IntQueue::~IntQueue() { delete[] queueArray; }

//------------------------------------------------------------------------------
// inserts a value at the rear (tail) of the queue
//------------------------------------------------------------------------------
void IntQueue::enqueue(int num) {

    if (isFull())
        cout << "The queue is full.\n";

    else {
        // calculate the new tail position
        rear = (rear + 1) % queueSize;

        // insert new item
        queueArray[rear] = num;

        // update item count
        numItems++;
    }
}

//------------------------------------------------------------------------------
// removes the value at the front of the queue and copies it into num
//------------------------------------------------------------------------------
void IntQueue::dequeue(int& num) {

    if (isEmpty()) {
        cout << "The queue is empty.\n";
        return;
    }

    // move front
    front = (front + 1) % queueSize;

    // retrieve the front item
    num = queueArray[front];

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
void IntQueue::clear() {
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}