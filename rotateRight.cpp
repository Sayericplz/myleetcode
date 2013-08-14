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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if(head == NULL || k == 0) return head;
        ListNode *p = head,*q;
        int len = 1;
        while(p->next!=NULL)
        {
        	p=p->next;
        	len++;
        }
        k = k%len;
        q = head;
        if(k == 0) return head;
        for(int i = 1;i < len-k;i++)
        {
        	q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = NULL;
        return head;
    }
};