class Solution {
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > res;
        vector<string> tmp;
        int n = s.size();
        if(!n) return res;
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
        dfs(res,tmp,next,0,s);
        return res;
    }

    void dfs(vector<vector<string> > &res,vector<string> &tmp,vector<vector<int>> &next,int pos,string &s)
    {
    	if(pos == s.size())
    	{
    		res.push_back(tmp);
    		return;
    	}
    	for(int i = 0;i < next[pos].size();i++)
    	{
    		tmp.push_back(s.substr(pos,next[pos][i]-pos+1));
    		dfs(res,tmp,next,next[pos][i]+1,s);
    		tmp.pop_back();
    	}
    }
};