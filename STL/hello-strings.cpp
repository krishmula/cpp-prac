#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1 = "cat";
    sort(str1.begin(), str1.end());
    cout << "Sorted string is: " << str1 << endl;
    // cout << "sorted string is: " << sorted_string << endl;
    // char str[] = "c++";
    // cout << "String is: " << str << endl;

    // string str2 = "hello new string string new hello string";
    // cout << "String 2 is: " << str2 << endl;
    // size_t first_occurrence = str2.find("new");
    // cout << "First Occurrence is: " << first_occurrence << endl;
    // size_t last_occurrence = str2.rfind("string");
    // cout << "Last Occurrence is: " << last_occurrence << endl;

    // str2.append("hello world");
    // cout << "Appended string is: " << str2 << endl;
    // int size = str2.length(); 
    // cout << size << endl;
}