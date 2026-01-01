#include <string>
#include <iostream>

using namespace std;

int main() {
    string s = "abc";
    string sCopy = s;

    cout << "string s before checking is: " << s << endl;

    string s1 = "abcd";

    if (s1.length() > s.length()) s = s1;

    cout << "string s after checking is: " << s << endl;

}
