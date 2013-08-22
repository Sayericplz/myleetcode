class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s = S.size(),t = T.size();
        vector<vector<int> > f(s+1,vector<int>(t+1,0));
        for(int i = 0;i <= s;i++)
        	f[i][0] = 1;
        for(int i = 1;i <= s;i++)
        {
        	for(int j = 1;j <= i && j <= t;j++)
        	{
        		if(S[i-1] == T[j-1])
        			f[i][j] = f[i-1][j-1]+f[i-1][j];
        		else
        			f[i][j] = f[i-1][j];
        	}
        }
        return f[s][t];
    }
};