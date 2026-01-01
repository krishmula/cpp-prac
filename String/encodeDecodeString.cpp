#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encodeString(vector<string>& strs) {
    string str = "";
    for (int i = 0; i<strs.size(); i++) {
      str.append(strs[i]);
    }
    return str;
}

vector<string> decodeString(string s, vector<int> charLength) {
    vector<string> result;
    int count = 0;
    string st = "";
    for (int i = 0; i<charLength.size(); i++) {
        st = s.substr(count, charLength[i]);
        count = count + charLength[i];
        result.push_back(st);
    }
    return result;
}

int main() {
    vector<string> strs = {"hello", "world", "i", "love", "you"};
    string s = "helloworldiloveyou";
    vector<int> charLength = {5, 5, 1, 4, 3};

    string encoded_string = encodeString(strs);
    cout << "The encoded string is: " << encoded_string << endl;

    vector<string> decodedString = decodeString(s, charLength);
    cout << "The decoded string is: " << endl;
    for (auto iter: decodedString) {
        cout << iter << endl;
    }
}