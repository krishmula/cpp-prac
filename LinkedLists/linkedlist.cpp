#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <stack>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val1, ListNode* next1) {
            val = val1;
            next = next1;
        }
        ListNode(int val1) {
            val = val1;
            next = nullptr;
        }
};

bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* temp = head;
        stack<int> chk;
        int cnt = 0;
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt/2 + 1;

        ListNode* trav = head;
        int cnt2 = 1;
        while (cnt2 < mid) {
            cnt2++;
            chk.push(trav->val);
            trav = trav->next;
        }

        if (cnt2 == mid && cnt%2 != 0) {
            trav = trav->next;
            while (trav != nullptr) {
                int actVal = trav->val;
                int popVal = chk.top();
                if (popVal != actVal) {
                    return false;
                }
                chk.pop();
                trav = trav->next;
            }
        } else {
            // chk.pop();
            while (trav != nullptr) {
                int actVal = trav->val;
                int popVal = chk.top();
                if (popVal != actVal) {
                    return false;
                }
                chk.pop();
                trav = trav->next;
            }
        }

        return true;
    }

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode* head = new ListNode(0);
        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        ListNode* temp = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        while (list1 != nullptr) {
            temp->next = list1;
            list1 = list1->next;
            temp = temp->next;
        }
        while (list2 != nullptr) {
            temp->next = list2;
            list2 = list2->next;
            temp = temp->next;
        }

        return head;
}

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
//    ListNode* list1 = new ListNode(1);
//    ListNode* temp1 = list1;
//    temp1->next = new ListNode(2);
//    temp1 = temp1->next;
//    temp1->next = new ListNode(4);

//    ListNode* list2 = new ListNode(1);
//    ListNode* temp2 = list2;
//    temp2->next = new ListNode(3);
//    temp2 = temp2->next;
//    temp2->next = new ListNode(4);

//    ListNode* head = mergeTwoLists(list1, list2);
//   printLL(head);

int a = 119/10;
int b = 119 % 10;
cout << b << " ";
cout << a;

}