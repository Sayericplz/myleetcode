class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        if(!n) return true;
        vector<vector<vector<bool> > > f(n,vector<vector<bool> >(n,vector<bool>(n,false)));
        for(int i = 0;i < n;i++)
        {
        	for(int j = 0;j < n;j++)
        	{
        		f[i][j][0] = s1[i]==s2[j];
        	}
        }
        for(int k = 1; k < n;k++)
        {
        	for(int i = 0;i+k < n;i++)
        	{
        		for(int j = 0;j+k < n;j++)
        		{
        			for(int l = 0;l < k;l++)
        			{
        				if((f[i][j][l]&&f[i+l+1][j+l+1][k-l-1])||(f[i][j+k-l][l]&&f[i+l+1][j][k-l-1]))
        				{
        					f[i][j][k] = true;
        					break;
        				}
        			}
        		}
        	}
        }
        return f[0][0][n-1];
    }
};