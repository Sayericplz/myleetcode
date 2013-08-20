class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return 0;
        int *num = new int[n];
        num[0] = 1;
        for(int i=1;i<n;i++)
        {
        	num[i] = 2*num[i-1];
        	for(int j = 1;j<i;j++)
        	{
        		num[i] += num[j-1]*num[i-j-1];
        	}
        }
        int res = num[n-1];
        delete []num;
        return res;
    }
};