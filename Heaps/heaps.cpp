#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string removeTrailingZeros(string s) {
    int n = s.length();

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            return s.substr(0, i + 1);
        }
    }
}

string removeLeadingZeros(string s) {
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] != '0') {
            return s.substr(i);
        }
    }
}

int main() {
    string s1 = "3";
    string s2 = "3030";

    int x = s2.rfind("0");

    cout << x << endl;

    int result = s1.compare(s2);

    // if (result < 0) {
    //     cout << s1 << " is less than " << s2 << endl;
    // } else if (result > 0) {
    //     cout << s1 << " is greater than " << s2 << endl;
    // } else {
    //     cout << s1 << " is equal to " << s2 << endl;
    // }

    if (s1 < s2) {
        cout << s1 << " is less than " << s2 << endl;
    } else if (s1 > s2) {
        cout << s1 << " is greater than " << s2 << endl;
    } else {
        cout << s1 << " is equal to " << s2 << endl;
    }

}