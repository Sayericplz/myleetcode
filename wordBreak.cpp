class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.size();
        if(len == 0) return true;
        vector<bool> flag(len+1,false);
        flag[0] = true;
        for(int i = 0;i < len;i++)
        {
        	if(flag[i])
        	{
        		for(int j = 1;j <= len - i;j++)
        		{
        			string ss = s.substr(i,j);
        			if(dict.find(ss) != dict.end())
        				flag[i+j] = true;
        		}
        	}
        }
        return flag[len];
    }
};