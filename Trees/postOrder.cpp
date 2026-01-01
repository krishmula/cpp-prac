#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node* right;

    Node() {
        this->val = 0;
        left = NULL;
    }
    Node (int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    Node (int val, Node* left, Node* right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 
};

void getPostOrder(Node* root, vector<int> &postOrder) {
    if (root == nullptr) return;
    getPostOrder(root->left, postOrder);
    getPostOrder(root->right, postOrder);
    postOrder.push_back(root->val);
}

vector<int> postOrderTraversal(Node* root) {
    vector<int> postOrder;
    getPostOrder(root, postOrder);
    return postOrder;
}

int main () {

    vector<int> res;
    
    Node* secondLeft = new Node(15);
    Node* secondRight = new Node(21);
    Node* thirdLeft = new Node(44);
    Node* thirdRight = new Node(55);
    Node* firstRight = new Node(9, thirdLeft, thirdRight);    
    Node* firstLeft = new Node(7, secondLeft, secondRight);
    Node* root = new Node(5, firstLeft, firstRight);
    res = postOrderTraversal(root);

    for (auto it: res) {
        cout << it << " ";
    }
}