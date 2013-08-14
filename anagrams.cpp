class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        map<string,vector<int> > flag;
        for(int i = 0;i < strs.size();i++)
        {
        	string tmp(strs[i]);
        	sort(tmp.begin(),tmp.end());
        	flag[tmp].push_back(i);
        }
        for(map<string,vector<int> >::iterator p = flag.begin(); p != flag.end();p++)
        {
        	if((p->second).size() > 1)
        	{
        		for(int i = 0;i < (p->second).size();i++)
        		{
        			res.push_back(strs[(p->second)[i]]);
        		}
        	}
        }
        return res;
    }
};