#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;
    for (int i = 0; i < 11; i++)
    {
        s.insert(++i);
    }
    cout << "Elements in the set: ";

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    if (s.count(10)) {
        cout << "10 exists" << endl;
    } else {
        cout << "10 doesn't exist" << endl;
    }
}