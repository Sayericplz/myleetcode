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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     	vector<int> num;
     	vector<TreeNode *> nodes;
     	inorderT(root,num,nodes);
     	sort(num.begin(),num.end());
     	for(int i = 0;i < num.size();i++)
     	{
     		nodes[i]->val=num[i];
     	}
    }

    void inorderT(TreeNode *root,vector<int> &num,vector<TreeNode *> &nodes)
    {
    	if(root->left != NULL) inorderT(root->left,num,nodes);
    	num.push_back(root->val);
    	nodes.push_back(root);
    	if(root->right != NULL) inorderT(root->right,num,nodes);
    }
};