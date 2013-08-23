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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int sum = 0;
        if(!root) return 0;
        calculate(root,sum,0);
        return sum;
    }

    void calculate(TreeNode *node,int &sum,int tmp)
    {
    	if(!node->left && !node->right)
    	{
    		sum += tmp*10+node->val;
    		return;
    	}
    	if(node->left)
    		calculate(node->left,sum,tmp*10+node->val);
    	if(node->right)
    		calculate(node->right,sum,tmp*10+node->val);
    }
};