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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int k = lists.size(),min,flag;
        if(k==0) return NULL;
        ListNode *head = NULL,*p,*q;
        vector<ListNode *>::iterator pos;
        flag = 1;

        while(flag == 1)
        {
            min = INT_MAX;
        	flag = 0;
        	for(vector<ListNode *>::iterator i = lists.begin();i<lists.end();i++)
        	{
        		if(*i == NULL)
        		{
     				continue;
        		}
        		flag = 1;
        		if((*i)->val < min)
        		{
        			min = (*i)->val;
        			pos = i;
        		}
        	}       	
        	if(flag == 1)
        	{
        		*pos = (*pos) -> next;
        		if(head == NULL)
        		{
        			p = new ListNode(min);
        			head = p;
        		}
        		else
        		{
        			q = new ListNode(min);
        			p->next = q;
        			p = q;
        		}
        	}
        }
        return head;
    }
};