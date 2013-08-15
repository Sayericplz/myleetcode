class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(k > n || k == 0) return res;
        vector<int> tmp;
        dfs(0,k,n,1,tmp,res);
        return res;
    }

    void dfs(int d,int maxd,int n,int s,vector<int> &tmp,vector<vector<int> > &res)
    {
    	if(d == maxd)
    	{
    		res.push_back(tmp);
    		return;
    	}
    	for(int i = s;i<=n;i++)
    	{
    		tmp.push_back(i);
    		dfs(d+1,maxd,n,i+1,tmp,res);
    		tmp.pop_back();
    	}
    }
};