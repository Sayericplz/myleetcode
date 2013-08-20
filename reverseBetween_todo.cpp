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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<ListNode*> p;
        ListNode *q = head;
        int cnt = 1;
        while(cnt <= n)
        {
        	if(cnt >= m-1)
        		p.push_back(q);
        	q = q->next;
        	cnt ++;
        }
        if(m == 1)
        {
        	q = p.back()->next;
        	for(int i = p.size()-1;i > 0;i--)
        	{
        		p[i]->next = p[i-1];
        	}
        	p[0]->next =q;
        	head = p.back();
        }
        else
        {
        	q = p.back()->next;
        	for(int i = p.size()-1;i > 1;i--)
        	{
        		p[i]->next = p[i-1];
        	}
        	p[1]->next = q;
        	p[0]->next = p.back();
        }
        return head;
    }
};