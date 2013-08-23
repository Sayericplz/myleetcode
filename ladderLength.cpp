class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(start == end) return 2;
        int mins = 0;
        unordered_set<string> unique;
        queue<string> que;
        que.push(start);
        unique.insert(start);
        int cnt = 1,nextcnt = 0;
        while(cnt)
        {
        	string s = que.front();
        	que.pop();
        	cnt--;
        	for(int i = 0;i < s.size();i++)
        	{
        		string tmp = s;
        		for(char c = 'a';c <= 'z';c++)
        		{
        			tmp[i] = c;
        			if(dict.find(tmp)!=dict.end()&&unique.find(tmp)==unique.end())
        			{
        				if(tmp == end)
        					return mins+2;
        				unique.insert(tmp);
        				que.push(tmp);
        				nextcnt++;
        			}
        		}
        	}
        	if(!cnt)
        	{
        		cnt = nextcnt;
        		nextcnt = 0;
        		mins++;
        	}
        }
        return 0;
    }
};