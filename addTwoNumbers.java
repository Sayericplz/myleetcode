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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int inc = 0;
        ListNode head = null,p = null;
        if(l1 == null) return l2;
        if(l2 == null) return l1;
        while(l1!=null && l2!=null)
        {
        	int sum = inc + l1.val+l2.val;
        	if(head == null)
        	{
        		head = new ListNode(sum % 10);
        		p = head;
        	}
        	else
        	{
        		p.next = new ListNode(sum % 10);
        		p = p.next;
        	}
        	inc = sum / 10;
        	l1 = l1.next;
        	l2 = l2.next;
        }
        if(l1 == null)
        {
        	while(l2 != null)
        	{
        		int sum = inc + l2.val;
        		p.next = new ListNode(sum%10);
        		p = p.next;
        		inc = sum/10;
        		l2 = l2.next;
        	}
        }
        if(l2 == null)
        {
        	while(l1 != null)
        	{
        		int sum = inc + l1.val;
        		p.next = new ListNode(sum%10);
        		p = p.next;
        		inc = sum/10;
        		l1 = l1.next;
        	}
        }
        if(inc > 0) p.next = new ListNode(inc);
        return head;
    }
}