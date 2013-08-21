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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
       	dfs(root,0,res);
       	for(int i = 0,j = res.size()-1;i<j;i++,j--)
       	{
       		vector<int> tmp = res[i];
       		res[i].clear();
       		res[i] = res[j];
       		res[j].clear();
       		res[j] = tmp;
       		tmp.clear();
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