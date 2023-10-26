#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        // Traverse both lists and compare the nodes to merge them in sorted order
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // If any list is remaining, append it to the merged list
        if (l1 != nullptr) {
            current->next = l1;
        } else {
            current->next = l2;
        }

        // Save the merged list and delete the dummy node
        ListNode* mergedList = dummy->next;
        delete dummy;
        return mergedList;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(l1, l2);

    std::cout << "Merged Sorted Linked List: ";
    printList(mergedList);

    // Clean up the memory
    delete l1;
    delete l2;
    // Free the merged list
    while (mergedList != nullptr) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
