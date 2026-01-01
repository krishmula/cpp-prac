#include <iostream>
#include <list>

using namespace std;

int main() {
    // This is basically a doubly linked list.
    list<int> myList = {1, 2, 3, 4, 5};

    cout << "lists allow to push elements to the beginning of the list too " << endl;
    myList.push_front(10); 
    myList.push_back(15);

    for (auto it: myList) {
        cout << it << " ";
    }
    cout << endl;

    cout << "Lists allow to pop elements from the front and back too" << endl;
    myList.pop_front();
    myList.pop_back();

    cout << "Lists allow to reverse them" << endl;
    myList.reverse();


    for (auto it: myList) {
        cout << it << " ";
    }
    cout << endl;

}