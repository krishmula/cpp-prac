#include <stdio.h>
#include <iostream>

using namespace std;

class Queue {
public:
    int head;
    int tail;
    int capacity;
    int* arr;

    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        int head = 0;
        int tail = 0;
    }

    void enqueue(int num) {
        if (tail >= capacity - 1) return;
        arr[tail] = num;
        tail++;
    }

    int dequeue() {
        if (head >= tail) return -1;
        int val = arr[head];
        head++;
        return val;
    }

    void printQueue() {
        if (head >= tail) return;
        for (int i = head; i<capacity; i++) {
            cout << arr[i];
        }
    }
};

int main()
{
    Queue myqueue(6 );
    myqueue.enqueue(1);
    myqueue.enqueue(2);
    myqueue.enqueue(3);
    myqueue.enqueue(4);
    myqueue.enqueue(6);

    int vals = myqueue.dequeue();
    cout << "The dequeued value is: " << vals << " ";
    myqueue.printQueue();
}