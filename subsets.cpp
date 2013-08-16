class Solution {

public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
    	vector<int> tmp;
    	sort(S.begin(),S.end());
        recursion(0,S,res,tmp);
        return res;
    }

    void recursion(int pos,vector<int> &S,vector<vector<int> > &res,vector<int> &tmp)
	{
		if(pos == S.size())
		{
			res.push_back(tmp);
			return;
		}
		tmp.push_back(S[pos]);
		recursion(pos+1,S,res,tmp);
		tmp.pop_back();
		recursion(pos+1,S,res,tmp);
	}
};