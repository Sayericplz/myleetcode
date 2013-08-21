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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        return check(root,sum,0);
    }

    bool check(TreeNode *root,int sum,int tmp)
    {
    	if(!root->left && !root->right)
    	{
    		if(tmp+root->val == sum)
    			return true;
    		return false;
    	}
    	if(!root->left)
    		return check(root->right,sum,tmp+root->val);
    	if(!root->right)
    		return check(root->left,sum,tmp+root->val);
    	return check(root->right,sum,tmp+root->val)||check(root->left,sum,tmp+root->val);
    }
};