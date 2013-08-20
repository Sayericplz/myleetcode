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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return check(root->left,root->right);
    }

    bool check(TreeNode *left, TreeNode *right)
    {
    	if(left == NULL && right == NULL) return true;
    	if((left == NULL && right != NULL)||(left != NULL && right == NULL)) return false;
    	return left->val==right->val && check(left->left,right->right) && check(left->right,right->left);
    }
};