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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k == 0 || k == 1) return head;
    	ListNode *p[k],*r,*pos;
        pos = head;
        int flag = 0,i;
        while(pos != NULL)
        {
        	flag ++;
        	if(flag < k)
        	{
        		for(i = 0; i < k-2;i++)
        		{
        			p[i] = p[i+1];
        		}
        		p[i] = pos;
        	}
        	else if(flag == k)
        	{
        		if(p[0] == head) 
        		{
        			head = pos;
				}
				else
				{
	        		r->next = pos;
				}
				p[k-1] = pos;
        		pos = pos->next;
        		p[k-1]->next = p[0];
        		for(i = k-1;i>0;i--)
        		{
        			p[i]->next = p[i-1];
        		}
        		p[0]->next = pos;
        		pos = p[0];
        		r = pos;
				flag = 0;
        	}
        	pos = pos->next;
        }
        return head;   
    }
};