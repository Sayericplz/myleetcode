class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.size();
        vector<string> res;
        if(len == 0) return res;
        vector<vector<int>> pre(len+1,vector<int>());    
        for(int i = 0;i < len;i++)
        {
            if(pre[i].size() || i == 0)
            {
                for(int j = 1;j <= len - i;j++)
                {
                    string ss = s.substr(i,j);
                    if(dict.find(ss) != dict.end())
                        pre[i+j].push_back(i);
                }
            }
        }
        vector<int> tmp;
        generate(pre,res,s,tmp,len);
        return res;
    }

    void generate(vector<vector<int>> &pre,vector<string> &res,string s,vector<int> &tmp,int pos)
    {
        if(pos == 0)
        {
            int start = 0;
            string ss = "";
            for(int i = tmp.size()-1;i >= 0;i--)
            {
                ss += s.substr(start,tmp[i]-start)+" ";
                start = tmp[i];
            }
            res.push_back(ss.substr(0,ss.size()-1));
            return;
        }
        tmp.push_back(pos);
        for(int i = 0;i < pre[pos].size();i++)
            generate(pre,res,s,tmp,pre[pos][i]);
        tmp.pop_back();
    }
};