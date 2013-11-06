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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head || !head->next || !head->next->next) return;
        ListNode *slow = head,*fast = head;
        while(fast){
        	fast = fast->next;
        	if(!fast) break;
        	slow = slow->next;
        	fast = fast->next;
        }
        ListNode *p,*q;
        fast = slow->next;
        while(fast){
        	p = fast->next;
        	fast->next = slow;
        	slow = fast;
        	fast = p;
        }
        p = head;q = slow;
        while(p != q && p->next != q){
        	fast = p;
        	slow = q;
        	p = p->next;
        	q = q->next;
        	fast->next = slow;
        	slow->next = p;
        }
        if(p == q) p->next = NULL;
        else q->next = NULL;
    }
};