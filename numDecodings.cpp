class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s.size() == 0) return 0;
        int n = s.size();
        vector<int> f(n,0);
        for(int i = 0;i < n;i++)
        {
        	if(i > 0)
        	{
        		string ss = s.substr(i-1,2);
        		if(ss>="10" && ss<="26")
        		{
        			if(i > 1) f[i] += f[i-2];
        			else f[i] += 1;
        		}
        	}
        	if(s[i]>='1' && s[i]<='9')
        	{
        		if(i > 0) f[i] += f[i-1];
        		else f[i] += 1;
        	}
        }
        return f[n-1];
    }
};