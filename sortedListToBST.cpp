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
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        ListNode *p = head;
        while(p)
        {
        	p=p->next;
        	len++;
        }
        return build(head,0,len-1);
    }

    TreeNode *build(ListNode *node,int beg,int end)
    {
    	if(beg > end) return NULL;
    	int mid = (beg+end)/2;
    	ListNode *p = node;
    	for(int i = beg;i < mid;i++)
    	{
    		p=p->next;
    	}
    	TreeNode *root = new TreeNode(p->val);
    	root->left = build(node,beg,mid-1);
    	root->right = build(p->next,mid+1,end);
    	return root;
    }
};