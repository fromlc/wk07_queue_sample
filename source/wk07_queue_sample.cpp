//------------------------------------------------------------------------------
// wk07_queue_sample.cpp
//
// Demos a queue of ints with the IntQueue class
// 
// Author: Tony Gaddis, from Gaddis 9E pp. 1198-1209
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "IntQueue.h"

#include <iostream>

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_VALUES = 5;	// queue capacity

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main()
{
    // create a queue to hold int values
    IntQueue iQueue(MAX_VALUES);

    // enqueue a series of items
    std::cout << "Enqueuing " << MAX_VALUES << " items...\n";

    for (int i = 0; i < MAX_VALUES; i++)
    {
        std::cout << "Enqueuing " << i << "\n";
        iQueue.enqueue(i);
    }

    // try to enqueue just one more item
    std::cout << "\nTrying to enqueue one more item..." << MAX_VALUES << "\n";
    iQueue.enqueue(MAX_VALUES);

    // dequeue and retrieve all items in the queue
    std::cout << "\nDequeueing values:\n";

    int value;
    while (!iQueue.isEmpty())
    {
        iQueue.dequeue(value);
        std::cout << value << '\n';
    }

    return 0;
}