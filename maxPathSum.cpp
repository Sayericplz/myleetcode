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
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 		int len;
 		return calculate(root,len);
    }

    int calculate(TreeNode *root,int &len)
    {
    	int left = INT_MIN,right = INT_MIN,llen = 0,rlen = 0;
    	if(root->left) left = calculate(root->left,llen);
    	if(root->right) right = calculate(root->right,rlen);
    	len = max(root->val,max(root->val+llen,root->val+rlen));
    	return max(max(root->val+llen+rlen,len),max(left,right));
    }
};