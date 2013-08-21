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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> t;
      	if(!root) return res;
      	check(root,sum,0,res,t);
      	return res;  
    }

    void check(TreeNode *root,int sum,int tmp,vector<vector<int> > &res,vector<int> &t);
    {
    	if(!root->left && !root->right)
    	{
    		if(tmp+root->val == sum)
    		{
    			t.push_back(root->val);
    			res.push_back(t);
    			t.pop_back();
    		}
    		return;
    	}
    	t.push_back(root->val);
    	if(root->left)
    		check(root->left,sum,tmp+root->val,res,t);
    	if(root->right)
    		check(root->right,sum,tmp+root->val,res,t);
    	t.pop_back();
    }
};