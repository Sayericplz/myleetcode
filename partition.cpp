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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL) return head;
        ListNode *p,*q,*r;
 		p = head;
 		if(p->val < x)
 		{
 			while(p->next != NULL && p->next->val < x)	p=p->next;
 			if(p->next == NULL) return head;
 			r = p;
 			p = p->next;
 			q = p->next;
 		}
 		else
 		{
 			while(p->next != NULL && p->next->val >= x) p=p->next;
 			if(p->next == NULL) return head;
 			r = p->next;
 			p->next = r->next;
 			r->next = head;
 			head = r;
 			q = p->next;
 		}
 		while(q != NULL)
 		{
 			if(q->val >= x)
 			{
 				p = q;
 				q = q->next;
 			}
 			else
 			{
 				p->next = q->next;
 				q->next = r->next;
 				r->next = q;
 				r = q;
 				q = p->next;
 			}
 		}
 		return head;
    }
};