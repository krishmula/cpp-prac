#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node* right;

    Node() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
    Node (int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node (int data, Node* left, Node* right) {
        this->data = data;
        this->left = left;
        this->right = right;
    } 
};

vector<int> getInorderTree(vector<int> arr, int index) {
    vector<int> inorder;

    if (index >= arr.size()) return inorder;

    getInorderTree(arr, index*2 + 1);
    inorder.push_back(arr[index]);
    getInorderTree(arr, index*2 + 2);

    return inorder;
}

void getInorder(Node* root, string temp, vector<string> &res) {
    
    if (root == nullptr) return;
    temp += to_string(root->data) + " ";
    if (root->left == nullptr && root->right == nullptr) {
        res.push_back(temp);
        return;
    }

    getInorder(root->left, temp, res);
    getInorder(root->right, temp, res);
}

void getPath(Node* root, vector<int> &arr, vector<int> &res, Node* A) {
    bool flag = false;
    if (root == nullptr) return;
    int val = A->data;
    arr.push_back(root->data);

    if (root->data == val) {
        copy(arr.begin(), arr.end(), back_inserter(res));
    };

    getPath(root->left, arr, res, A);
    getPath(root->right, arr, res, A);

    arr.pop_back();
}

vector<string> rootToLeaf(Node* root) {
    vector<string> res;
    getInorder(root, "", res);
    return res;
}

int main () {
    // vector<int> arr = {1, 2, 4, 5, 3, -1, -1, -1, -1, -1, -1};
    // vector<int> inorder = getInorderTree(arr, 0);

    // for (int i = 0; i<inorder.size(); i++) {
    //     cout << " " << inorder[i];
    // }
    Node* secondLeft = new Node(15);
    Node* secondRight = new Node(21);
    Node* thirdLeft = new Node(44);
    Node* thirdRight = new Node(55);
    Node* firstRight = new Node(9, thirdLeft, thirdRight);    
    Node* firstLeft = new Node(7, secondLeft, secondRight);
    Node* root = new Node(5, firstLeft, firstRight);

    // vector<string> res;
    // res = rootToLeaf(root);
    // for (auto it: res) {
    //     cout << it << "  ->   ";
    // }
    vector<int> arr;
    vector<int> res;
    getPath(root, arr, res, thirdLeft);
    for (auto it: res) {
        cout << it << " -> ";
    }
}


