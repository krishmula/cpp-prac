#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    string s = "hello world";
    s.erase(s.size() - 1, 1);
    cout << s << endl;
}
