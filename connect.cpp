/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *pre = NULL,*p;
        queue<TreeLinkNode *> q;
        if(root) q.push(root);
        int dep = 0;
        int cnt = pow(2,dep++)-1; 
        while(!q.empty())
        {      	
        	p = q.front();
        	q.pop();
        	if(p->left)
        	{
        		q.push(p->left);
        		q.push(p->right);
        	}
        	if(pre) 
        	{
        		pre->next = p;
        		cnt--;
        	}
        	pre = p;       	
        	if(!cnt)
        	{
        		cnt = pow(2,dep++)-1;
        		p->next = NULL;
        		pre = NULL;
        	} 
        } 
    }
};