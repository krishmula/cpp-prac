#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};


    nums.push_back(6);
    nums.push_back(7);
    nums.insert(nums.end(), 12);
    nums.insert(nums.end() - 1, 10);
    nums.insert(nums.end() - 2, 11);

    for (auto it: nums) {
        cout << it << " ";
    }


    cout << "size of the vector is: " << nums.size() << endl;
    cout << "first element of the vector is: " << nums.front() << endl;
    cout << "last element of the vector is: " << nums.back() << endl;
}