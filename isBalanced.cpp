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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int dep;
        return check(root,dep);
    }

    bool check(TreeNode *node,int &dep)
    {
    	if(!node)
    	{
    		dep = 0;
    		return true;
    	}
    	int ld = 0,rd = 0;
    	bool lb = check(node->left,ld);
    	bool rb = check(node->right,rd);
    	dep = max(ld,rd) + 1;
    	return lb && rb && abs(ld-rd) < 2;
    }
};