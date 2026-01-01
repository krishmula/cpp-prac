#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // dynarr is of type int*, which mea
    int* dynarr = new int[size];
    for (int i = 0; i < size; i++)
    {
        dynarr[i] = i * 2;
    }

    cout << "Address of dynarr is " << dynarr << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Address of dynarr element " << i << "is" << &dynarr[i] << endl;
        cout << "Value of dynarr element " << i << "is" << dynarr[i] << endl;
    }

    cout << endl;

    delete[] dynarr;
    dynarr = nullptr;
}