#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        // int n=0;
        while(curr)
        {
            // n++;
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head->next) return head;

        //reverse list
        head = reverse(head);

        ListNode* temp = head;
        int n=0;
        for(temp; temp->next!=NULL; temp=temp->next)n++;
        n++;
        int i=k%n;

        while(i>0)
        {
            temp->next = head;
            head = head->next;
            temp = temp->next;
            temp->next = NULL;
            i--;
        }

        head = reverse(head);

        return head;
  
    }

    void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

    void printList(ListNode* head)
    {
        ListNode* temp = head;
        while(temp)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
};

int main() {
    Solution s;
    ListNode* head = NULL;
    s.insertNode(head, 1);
    s.insertNode(head, 2);
    s.insertNode(head, 3);
    s.insertNode(head, 2);
    s.insertNode(head, 1);
    s.printList(head);
    head = s.rotateRight(head, 2);
    cout<<endl;
    s.printList(head);
    return 0;
}
