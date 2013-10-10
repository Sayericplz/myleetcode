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
    public ListNode mergeKLists(ArrayList<ListNode> lists) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(lists.size() == 0) return null;
        if(lists.size() == 1) return lists.get(0); 
        PriorityQueue heap = new PriorityQueue(lists.size(),new Comparator<ListNode>(){
        	public int compare(ListNode a,ListNode b)
        	{
        		return a.val - b.val;
        	}
        });
        for(ListNode node : lists)
        {
        	if(node != null)
        		heap.add(node);
        }
        ListNode head = new ListNode(0), p = head;
        while(!heap.isEmpty())
        {
        	ListNode node = (ListNode)heap.poll();
        	if(node.next != null)
        		heap.add(node.next);
        	p.next = node;
        	p = node;
        }
        return head.next;
    }
}