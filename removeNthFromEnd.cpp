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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p[n+1];
        ListNode *pos;
        pos = head;
        while(pos != NULL)
        {
        	for(int i = 0;i < n;i++)
        	{
        		p[i] = p[i+1];
        	}
        	p[n] = pos;
        	pos = pos->next;
        }
        if(p[1] == head)
        {
        	pos = head;
        	head = head->next;
        	delete pos;
        	return head;
        }
        else
        {
        	pos = p[1];
        	if(n == 1)
        	{
        		p[0]->next = NULL;
        	}
        	else
        	{
        		p[0]->next = p[2];
        	}
        	delete pos;
        	return head;
        }
    }
};