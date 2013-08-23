class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(!n) return 0;
        vector<vector<bool> > f(n,vector<bool>(n,false));
        for(int i = n-1;i >= 0;i--)
        {
            for(int j = i;j < n;j++)
        	{
        		if(s[i]==s[j])
        		{
        			if(j-i<3)
        				f[i][j]=true;
        			else
        				f[i][j]=f[i+1][j-1];
        		}
        	}
        }
        vector<vector<int> > next(n);
        for(int i = 0;i < n;i++)
        {
        	for(int j = i;j < n;j++)
        	{
        		if(f[i][j])
        			next[i].push_back(j);
        	}
        }
       	f.clear();
       	vector<int> cuts(n,INT_MAX);
       	for(int i = n-1;i >= 0;i--)
       	{
       		for(int j = 0;j < next[i].size();j++)
       		{
       			int cut;
       			if(next[i][j] = n-1)
       				cut = 1;
       			else
       				cut = 1+cuts[next[i][j]+1];
       			if(cut<cuts[i]) cuts[i] = cut;
       		}
       	}
        return cuts[0];
    }
};