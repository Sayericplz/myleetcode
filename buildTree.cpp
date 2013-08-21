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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!inorder.size()) return NULL;
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder,int b1,int e1,int b2,int e2)
    {
        if(b1 > e1) return NULL;
    	TreeNode *root = new TreeNode(preorder[b1]);
    	int pos;
    	for(int i = b2;i <= e2;i++)
    	{
    		if(preorder[b1] == inorder[i])
    		{
    			pos = i;
    			break;
    		}
    	}
    	root->left = build(preorder,inorder,b1+1,b1+pos-b2,b2,pos-1);
    	root->right = build(preorder,inorder,b1+pos-b2+1,e1,pos+1,e2);
        return root;
    }
};