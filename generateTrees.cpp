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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return generate(1,n);
    }

    vector<TreeNode *> generate(int beg,int end)
    {
    	vector<TreeNode *> res;
    	if(beg > end)
    	{	
    		res.push_back(NULL);
    		return;
    	}
    	for(int i = 1;i <= n;i++)
    	{
    		vector<TreeNode *> left = generate(beg,i-1);
    		vector<TreeNode *> right = generate(i+1,end);
    		for(int j = 0;j < left.size();j++)
    		{
    			for(int k = 0;k < right.size();k++)
    			{
    				TreeNode *t = new TreeNode(i);
    				t->left = left[j];
    				t->right = right[k];
    				res.push_back(t);
    			}
    		}
    	}
    }
};