class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        int num = words.size();
        if(!num) return res;
        if(!L) return words;
        int start = 0,end = 0;
        while(start < num)
        {
            string s= "";
        	int cnt = 1;
        	int len = words[start].size();
        	while(end < num-1 && len+words[end+1].size()+1 <= L)
        	{
        		len += words[++end].size()+1;
        		cnt ++;
        	}
        	int blank = L - len + cnt - 1;
        	if(end == num - 1 && blank > 0) 
        	{	
        		blank = end - start+1;
        		cnt ++;
        	}
        	for(int i = start;i <= end;i++)
        	{
        		s += words[i];
        		if(blank)
        		{
        			if(cnt > 1) cnt--;
	        		int b = blank/(cnt);
	        		if(blank%(cnt)>0) b++;
	        		string tmp(b,' ');
	        		s+=tmp;
	        		blank -= b;
        		}
        	}
        	s += string(L-s.size(),' ');
        	res.push_back(s);
        	start = ++end;
        }
        return res;
    }
};