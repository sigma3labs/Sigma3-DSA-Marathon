// Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.
// For example : 
// Input:
// LinkedList: 25->36->47->58->69->80
// data: 19
// Output: 
// 19 25 36 47 58 69 80

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}
class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        struct Node *p = new Node(data);
        struct Node *t = head;
        
        if(data < head->data){
            p->next = head;
            head = p;
        }else{
            while(t->next != NULL && data > t->next->data){
                t = t->next;
            }
            p->next = t->next;
            t->next = p;
        }
        return head;
    }
};
int main() 
{ 
	
		int n;
		cin>>n;
        
		int data;
		cin>>data;
		
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		
		int k;
		cin>>k;
		Solution obj;
		head = obj.sortedInsert(head,k);
		printList(head); 
	  return 0; 
} 
