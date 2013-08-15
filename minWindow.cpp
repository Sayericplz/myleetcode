class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = S.size(),lt = T.size();
        if(lt < 1 || lt > ls) return "";
        int count[256] = {0};
        int flag[256] = {0};
        for(int i = 0;i < lt;i++) 
        {
            count[T[i]] ++;
        	flag[T[i]] = 1;
        }
        int min = INT_MAX,start = 0,end = 0;
        string res= "";
        while(end < ls)
        {
        	if(flag[S[end]])
        	{
        		count[S[end]] -- ;
        		if(count[S[end]] >= 0)
        			lt--;
        	}
        	if(!lt)
        	{
        		while(!flag[S[start]] || count[S[start]] < 0)
        		{      			
        			if(count[S[start]] < 0)
        				count[S[start]]++;
                    start ++;
        		}
        		if(end-start+1 < min)
        		{
        			min = end-start+1;
        			res = S.substr(start,min);
        		}
        		lt++;
        		count[S[start++]] += 1;
        	}
        	end++;
        }
        return res;
    }
};