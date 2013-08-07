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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p,*q,*r,*pos;
        pos = head;
        int flag = 0;
        while(pos != NULL)
        {
        	flag ++;
        	if(flag == 1)
        	{
        		p = pos;
        	}
        	else if(flag == 2)
        	{
        		if(p == head) 
        		{
        			head = pos;
				}
				else
				{
	        		r->next = pos;
				}
				q = pos;
        		pos = pos->next;
        		q->next = p;
        		p->next = pos;
        		pos = p;
        		r = pos;
				flag = 0;
        	}
        	pos = pos->next;
        }
        return head;
    }
};