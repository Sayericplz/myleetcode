/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> s;
        TreeNode *p = NULL,*q;
        if(root) s.push_back(root);
        while(!s.empty())
        {
        	q = s.back();
        	s.pop_back();
        	if(p) p->right = q;
        	p = q;
        	while(1)
        	{
				if(q->right) s.push_back(q->right);
				if(q->left)
				{
					q = q->left;
					p->right = q;
					p = q;
				}
				else 
					break;
        	}
        }
    }
};