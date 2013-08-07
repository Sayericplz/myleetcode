class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        string tmp(n*2,' ');
        getResult(ret,tmp,0,0);
        return ret;
    }

    void getResult(vector<string> &ret,string &tmp,int left,int pos)
    {
    	if(pos==tmp.size())
    	{
    		ret.push_back(tmp);
    		return;
    	}
    	if(left == 0)
    	{
    		tmp[pos]='(';
    		getResult(ret,tmp,left+1,pos+1);
    	}
    	else if(left == tmp.size()/2||tmp.size()-pos<=left)
    	{
    		tmp[pos]=')';
			getResult(ret,tmp,left-1,pos+1);
    	}
    	else
    	{
    		tmp[pos]='(';
    		getResult(ret,tmp,left+1,pos+1);
    		tmp[pos]=')';
			getResult(ret,tmp,left-1,pos+1);
    	}
    }
};