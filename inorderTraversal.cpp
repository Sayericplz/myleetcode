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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        vector<bool> f;
        vector<TreeNode*> nodes;
        if(root == NULL) return res;
        nodes.push_back(root);
        f.push_back(true);
        while(!nodes.empty())
        {
        	int i = nodes.size()-1;
        	if(nodes[i]->left != NULL && f[i])
        	{
        		f[i] = false;
        		nodes.push_back(c->left);
        		f.push_back(true);      		
        	}
        	else
        	{
        		res.push_back(nodes[i]->val);
        		TreeNode *c = nodes[i];
        		nodes.pop_back();
        		f.pop_back();
        		if(nodes[i]->right != NULL)	
        		{
        			nodes.push_back(nodes[i]->right);
        			f.push_back(true);
        		}
        	}
        }
        return res;
    }
};