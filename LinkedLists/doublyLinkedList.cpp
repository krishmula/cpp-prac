#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *back;

    Node(int val1, Node *next1, Node *back1)
    {
        val = val1;
        next = next1;
        back = back1;
    }

    Node(int val1)
    {
        val = val1;
        next = nullptr;
        back = nullptr;
    }
}

Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    // Initialize 'prev' to the head node
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node
        prev->next = temp; 
         // Move 'prev' to the newly created node for the next iteration
        prev = temp;       
    }
    // Return the head of the doubly linked list
    return head;  
}

Node* insertAtTail(Node *head, int k)
{
    Node *temp = head;
    Node *tail = new Node(k);

    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    temp->next = tail;
    tail->back= temp;

    return head;
}

int main()
{
    vector<int> arr = {4, 10, 3, 5};
    int k = 20;

    Node *head = convertArr2DLL(arr);
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }

    head = insertAtTail(head, 20);
    Node *temp1 = head;
    while (temp1 != nullptr)
    {
        cout << temp1->val << " ";
        temp1 = temp1->next;
    }
}