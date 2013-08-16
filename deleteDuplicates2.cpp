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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
        ListNode *p = head;
        ListNode *q = p->next;
        ListNode *r = NULL;
        ListNode *tmp;
        while(q != NULL)
        {
        	if(q->val == p->val)
        	{
        		while(q->next!=NULL && q->next->val == p->val) q = q->next;
        		if(r == NULL) 
        			head = q->next;
        		else
        			r->next = q->next;
 				while(p!=q->next)
 				{
 					tmp = p;					
 					p = p->next;
 					delete tmp;
 				}
        	}
        	else
        	{
        		r = p;
        		p = q;
        	}
			if(p == NULL) return head;
			q = p->next;
        }
        return head;
    }
};