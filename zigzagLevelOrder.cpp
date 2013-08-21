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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
       	dfs(root,0,res);
       	for(int i = 0;i < res.size();i++)
       	{
       		if(i%2)
       		{
       			for(int j = 0,k = res[i].size()-1;j < k;j++,k--)
       			{
       				int tmp = res[i][j];
       				res[i][j] = res[i][k];
       				res[i][k] = tmp;
       			}
       		}
       	}
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