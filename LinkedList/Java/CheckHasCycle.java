/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slowptr = head;
        ListNode fastptr = head;
        while(slowptr!= null && fastptr!=null){
            slowptr = slowptr.next;
            if(fastptr.next!=null){
                fastptr = fastptr.next.next;
            }
            else{
                return false;
            }
            if(slowptr == fastptr){
                return true;
            }
        }
        return false;
    }
}