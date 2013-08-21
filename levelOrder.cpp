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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
       	dfs(root,0,res);
       	return res;
    }

    void dfs(TreeNode *root,int d,vector<vector<int> > &res)
    {
    	if(!root) return;
    	if(d == res.size())
    		res.push_back(vector<int>());
    	res[d].push_back(root->val);
    	dfs(root->left,d+1,res);
    	dfs(root->right,d+1,res);
    }
};