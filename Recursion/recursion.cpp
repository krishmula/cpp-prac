#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <cstdlib>
#include <regex>

using namespace std;
bool isNegative = false;

int main() {
    string s = "  +420";
    int n = s.size();
    for (int i = 0; i<n; i++) {
        if (s[i] == ' ') continue;
        if (s[i] == '-') {
            isNegative = true;
            continue;
        }
        if (s[i] == '+') continue;
        
        cout << s[i];
    }
}