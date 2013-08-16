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
 		while(p != NULL && p->val >= x)
 		{
 			p = p->next;
 		}
 		if(p == NULL) return head;
 		if(p != head)
 		{
 		 	head->next = p->next;
 			p->next = head;
 			head = p;
 		}
 		r = head;
 		p = head->next;
 		q = p;

        return head;
    }
};