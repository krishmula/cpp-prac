#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node() {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int val, Node* left, Node* right) {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

vector<int> arr = {4,9,19,7,11,17,28,4,8,10,13,15,18,26,31};

int key = 7;
int ind;

for(int i = 0; i<arr.size(); i++) {
    if (arr[i] == key) {
        ind = i;
        break;
    }
}

vector<int> res = {};



// while (ind <= arr.size()) {
    
// }



