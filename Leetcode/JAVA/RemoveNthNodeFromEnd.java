/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        int count=0;
        while(temp!=null){
            count++;
            temp=temp.next;
        }
        if(n==1 && count==1){
            head=null;
            return head;
        }
        if(n==count){
            head=head.next;
            return head;
        }
        ListNode ins=head;
        while(count-n>1){
            ins=ins.next;
            count--;
        }
        ListNode del=ins.next;
        ins.next=del.next;
        del=null;
        return head;
    }
}
