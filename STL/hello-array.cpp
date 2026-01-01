#include <iostream>
#include <array>

using namespace std;

int main() {
    array<int, 5> newArray = {1, 2, 3, 4, 5};
    cout << "The fifth element is: " << newArray[4] << endl; 

    cout << "The size of the array is: " << newArray.size() << endl;
}