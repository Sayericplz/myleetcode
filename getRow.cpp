class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(rowIndex+1);
        res[0] = 1;
        for(int i = 1;i <= rowIndex;i++)
        {
        	for(int j = i;j >= 0;j--)
        	{
        		if(j==i) res[j] = res[j-1];
        		else if(j==0) res[j] = 1;
        		else res[j] += res[j-1];
        	}
        }
        return res;
    }
};