class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(strs.size()==0)
        {
        	return "";
        }
        int i,j,pos;
        char c;
        for(i=0;i<strs.size();i++)
        {
        	if(strs[i].size()==0)
        	{
        		return "";
        	}
        }

        for(i=0;i<strs[0].size();i++)
        {
        	c = strs[0][i];
        	for(j=1;j<strs.size();j++)
        	{
        		if(strs[j].size()<i+1 || strs[j][i]!=c)
        		{
        			return strs[0].substr(0,i);
        		}
        	}
        }
        return strs[0].substr(0,i);
    }
};