class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        if(!numRows) return res;
        res.push_back(vector<int>(1,1));
        vector<int> tmp;
        for(int i = 2;i < numRows;i++)
        {
        	tmp.clear();
        	tmp.push_back(1);
        	for(int j = 0;j < res[i-2].size()-1;j++)
        	{
        		tmp.push_back(res[i-2][j]+res[i-2][j+1]);
        	}
        	tmp.push_back(1);
        	res.push_back(tmp);
        }
        return res;
    }
};