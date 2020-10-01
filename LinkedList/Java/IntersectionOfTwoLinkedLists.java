/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int l1 = 0;
        int l2 = 0;
        ListNode cur = headA;

        ListNode res = null;
        while(cur!=null){
            cur = cur.next;           
            l1++;
        }
        cur = headB;
        while(cur!=null){
            cur = cur.next;
            l2++;
        }
        if(l1 == l2){
            if(headA == headB){
                return headA;
            }
        }
        int maxLimit = 0;
        if(l1 > l2){
            maxLimit = l1 - l2;
            cur = headA;
            ListNode curB = headB;
            for(int i = 0;i<maxLimit;i++){
                cur = cur.next;
                
                
            }
            while(cur!=null){
                if(cur == curB){
                    res = cur;
                    break;
                    
                }else{
                    cur = cur.next;
                    curB = curB.next;
                }
            }
        }
        else{
            maxLimit = l2 - l1;
            cur = headB;
            ListNode curA = headA;
            for(int i = 0;i<maxLimit;i++){
                cur = cur.next;
            }
            while(cur!=null){
                if(cur == curA){
                    res = cur;
                    break;
                    
                    
                }else{
                    cur = cur.next;
                    curA = curA.next;
                }
            }
        }
        return res;
        
    }
}