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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
           if(root==NULL) return true;
     	vector<int> num;
     	inorderT(root,num);
     	for(int i = 1;i < num.size();i++)
     	{
     		if(num[i] <= num[i-1]) return false;
     	}
     	return true;
    }

    void inorderT(TreeNode *root,vector<int> &num)
    {
    	if(root->left != NULL) inorderT(root->left,num);
    	num.push_back(root->val);
    	if(root->right != NULL) inorderT(root->right,num);
    }
};