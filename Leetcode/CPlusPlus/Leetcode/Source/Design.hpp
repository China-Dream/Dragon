#ifndef _DESIGN_HPP_
#define _DESIGN_HPP_

#include "Solution.h"

/* #622
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
https://leetcode-cn.com/problems/design-circular-queue
*/

class MyCircularQueue : public Solution
{
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        buff.resize(k + 1);
        head = tail = 0;
        size = k + 1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (head == (tail + 1) % size)
        {
            return false;
        }

        buff[tail] = value;
        tail = ++tail % size;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (head == tail)
        {
            return false;
        }

        head = ++head % size;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return head != tail ? buff[head] : -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        return head != tail ? buff[(tail - 1 + size) % size] : -1;
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return head == tail;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return head == (tail + 1) % size;
    }

    std::vector<int> buff;
    int head;
    int tail;
    int size;

    MyCircularQueue() = default;

    virtual void Run()
    {
        int k = 3;
        buff.resize(k + 1);
        head = tail = 0;
        size = k + 1;


        cout << enQueue(1) << endl;
        cout << enQueue(2) << endl;
        cout << enQueue(3) << endl;
        cout << enQueue(4) << endl;
        cout << Rear() << endl;
        cout << isFull() << endl;
        cout << deQueue() << endl;
        cout << enQueue(4) << endl;
        cout << Rear() << endl;
    }
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/

#endif