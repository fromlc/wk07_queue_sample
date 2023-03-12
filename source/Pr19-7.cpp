//------------------------------------------------------------------------------
// Pr19-7.cpp
//
// Demos a queue of ints with the IntQueue class
// 
// Author: Tony Gaddis, from Gaddis 9E pp. 1198-1209
// Modified by: Prof. Linda C
//------------------------------------------------------------------------------
#include "IntQueue.h"

#include <iostream>
using std::cout;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int MAX_VALUES = 5;	// queue capacity

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // create a queue to hold int values
    IntQueue iQueue(MAX_VALUES);

    // enqueue a series of items
    cout << "Enqueuing " << MAX_VALUES << " items...\n";

    for (int x = 0; x < MAX_VALUES; x++)
        iQueue.enqueue(x);

    // try to enqueue just one more item
    cout << "\nTrying to enqueue one more item...\n";
    iQueue.enqueue(MAX_VALUES);

    // dequeue and retrieve all items in the queue
    cout << "\nQueue values:\n";
    while (!iQueue.isEmpty()) {
        int value;
        iQueue.dequeue(value);
        cout << value << '\n';
    }

    return 0;
}