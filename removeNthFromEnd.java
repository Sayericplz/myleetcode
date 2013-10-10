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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode fast = head,slow = head,pre = null;
        for(int i = 0;i < n;i++) fast = fast.next;
        while(fast != null)
        {
        	pre = slow;
        	slow = slow.next;
        	fast = fast.next;
        }
        if(pre == null) return slow.next;
        pre.next = slow.next;
        return head;
    }
}