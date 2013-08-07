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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1 && !l2)
        {
        	return NULL;
        }
        else if(!l1)
        {
        	return l2;
        }
        else if(!l2)
        {
        	return l1;
        }
        ListNode *pre,*next,*head;
        int tmp,flag;
        tmp = l1->val + l2->val;
        if(tmp >= 10)
        {
        	flag = 1;
        	tmp = tmp%10;
        }
        else
        {
        	flag = 0;
        }
        head = new ListNode(tmp);
        pre = head;
        l1=l1->next;
        l2=l2->next;
        while(l1!=NULL || l2!=NULL)
        {
        	if(!l1)
        	{
        		tmp = l2->val+flag;
        		l2 = l2->next;
        	}
        	else if(!l2)
        	{
        		tmp = l1->val+flag;
        		l1 = l1->next;
        	}
        	else
        	{
        		tmp = l1->val+l2->val+flag;
        		l1 = l1->next;
        		l2 = l2->next;
        	}
        	if(tmp >= 10)
        	{
        		flag = 1;
        		tmp = tmp%10;
       	 	}
        	else
        	{
        		flag = 0;
        	}
        	next = new ListNode(tmp);
        	pre->next = next;
        	pre = next;
        }
        if(flag)
        {
        	next = new ListNode(1);
        	pre->next = next;
        }
        return head;
    }
};