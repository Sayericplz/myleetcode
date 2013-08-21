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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return build(num,0,num.size()-1);
    }

    TreeNode *build(vector<int> &num,int beg,int end)
    {
    	if(beg > end) return NULL;
    	int mid = (beg + end)/2;
    	TreeNode *root = new TreeNode(num[mid]);
    	root->left = build(num,beg,mid-1);
    	root->right = build(num,mid+1,end);
    	return root;
    }
};