#include <iostream>
using namespace std;

int main()
{
    int var1 = 12;
    int var2 = 15;
    int var3 = 22;
    string var4 = "helloworld";

    int newarr[10];

    cout << "The memory address of newarr is: " << newarr << endl;

    // The point_var variable is a pointer to an int.
    int *point_int = &var1;
    string *point_string = &var4;

    cout << "Address of var1 is: " << point_int << endl;
    cout << "Address of var2 is: " << &var2 << endl;
    cout << "Address of var3 is: " << &var3 << endl;
    cout << "Address of var4 is: " << point_string << endl;
}