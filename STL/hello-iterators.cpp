#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int>::iterator it = v.begin();
    vector<int>::iterator it2 = v.end();

    cout << "Last element: " << *it2 << endl;
}