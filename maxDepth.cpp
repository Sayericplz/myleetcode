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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        dfs(root,max,1);
        return max;
    }

    void dfs(TreeNode *root,int &max,int depth)
    {
    	if(!root) return;
    	if(depth > max) max = depth;
    	dfs(root->left,max,depth+1);
    	dfs(root->right,max,depth+1);
    }
};