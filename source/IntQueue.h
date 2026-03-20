//------------------------------------------------------------------------------
// IntQueue.h : class declaration/specification
//------------------------------------------------------------------------------
#ifndef INTQUEUE_H
#define INTQUEUE_H

class IntQueue
//------------------------------------------------------------------------------
{
private:
    int *queueArray;  // Points to the queue array
    int queueSize;    // The queue size
    int front;        // Subscript of the queue front
    int rear;         // Subscript of the queue rear
    int numItems;     // Number of items in the queue

public:
    // constructor
    IntQueue(int size);

    // copy constructor
    IntQueue(const IntQueue &);

    // destructor
    ~IntQueue();

    // queue operations
    void enqueue(int value);
    void dequeue(int &value);
    void peekFront(int &value);

    bool isEmpty() const;
    bool isFull() const;
    void clear();
};
#endif // INTQUEUE_H