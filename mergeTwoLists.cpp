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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *head,*p1 = l1,*p2 = l2,*q;
        if(p1->val < p2->val) 
        {
        	head = p1;
        	p1=p1->next;
        }
        else
        {
        	head = p2;
        	p2=p2->next;
        }
        q = head;
        while(p1 != NULL && p2!= NULL)
        {
        	if(p1->val < p2->val)
        	{
        		q->next = p1;
        		p1 = p1->next;
        	}
        	else
        	{
        		q->next = p2;
        		p2 = p2->next;
        	}
        	q = q->next;
        }
        if(p1!=NULL) q->next = p1;
        else q->next = p2;
        return head;
    }
};