class Solution
{
    // This is a function to find the data of nth node from the end of a linked list.
    int getNthFromLast(Node head, int n)
    {
    	// Your code here
    	if(head == null) {
    	    return -1;
    	}
    	Node first = head;
    	for(int i=0; i<n; i++) {
    	    if(first == null) {
    	        return -1;
    	    }
    	    first = first.next;
    	}
    	Node second = head;
    	while(first != null) {
    	    first = first.next;
    	    second = second.next;
    	}
    	return second.data;
    }
}
