/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *slow = head, *fast = head;
        while(fast){
        	slow = slow->next;
        	fast = fast->next;
        	if(!fast) return NULL;
        	fast = fast->next;
        	if(fast == slow){
        		fast = head;
        		while(fast != slow){
        			fast = fast->next;
        			slow = slow->next;
        		}
        		return fast;
        	}
        }
        return NULL;
    }
};