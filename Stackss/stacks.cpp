#include <stdio.h>
#include <iostream>

using namespace std;

class Stack {
public:
    int topper;
    int* arr;
    int capacity;

    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        topper = -1;
    }

    int isFull() {
        if (topper == capacity-1) return 1;
        else return 0;
    }

    int isEmpty() {
        if (topper == -1) return 1;
        else return 0;
    }

    void push(int num) {
        if (isFull()) {
            return;
        }
        topper++;
        arr[topper] = num;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int temp = arr[topper];
        topper--;
        return temp;
    }

    void printStack() {
        if (isEmpty()) return;
        for (int i = 0; i<capacity; i++) {
            cout << arr[i];
        }
    }

    int top() {
        if (isEmpty()) return 1;
        return arr[topper];
    }

};

int main() 
{
    Stack mystack(5);

    mystack.push(56);

    int val = mystack.top();
    
    cout << val;

    // mystack.printStack();

}