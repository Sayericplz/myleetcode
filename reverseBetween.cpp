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
        ListNode *p=head,*q,*pre=NULL,*r;
        int cnt = 1;
        while(cnt < m)
        {
            pre = p;
            p = p->next;
            cnt ++;
        }
        r = p;
        while(cnt < n)
        {
            q = p->next;
            p->next = q->next;
            q->next = r;
            r = q;
            //p = p->next;
            cnt++;
        }
        if(pre == NULL)
        {
            return r;
        }
        pre->next = r;
        return head;
    }
};