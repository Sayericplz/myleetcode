struct cnter{
	int val;
	int cnt;
	cnter(int v,int c):val(v),cnt(c){}
};

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<cnter> c;
        sort(S.begin(),S.end());
        for(int i = 0;i < S.size();i++)
        {
        	if(c.empty() || c.back().val != S[i])
        	{
        		struct cnter ct(S[i],1);
        		c.push_back(ct);
        	}
        	else
        	{
        		c.back().cnt ++;
        	}
        }
        vector<int> tmp;
        recursion(res,tmp,c,0);
        return res;
    }

    void recursion(vector<vector<int> > &res,vector<int> &tmp,vector<cnter> &c,int pos)
    {
    	if(pos == c.size())
    	{
    		res.push_back(tmp);
    		return;
    	}
    	for(int i = 0;i <= c[pos].cnt;i++)
    	{
    		for(int j = 0;j < i;j++) tmp.push_back(c[pos].val);
    		recursion(res,tmp,c,pos+1);
    		for(int j = 0;j < i;j++) tmp.pop_back();
    	}
    }
};