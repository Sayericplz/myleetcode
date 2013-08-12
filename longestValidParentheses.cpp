class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> flag;
        int maxlen = 0,size = s.size(),i,tmp,left = 0;
        flag.push_back(-1);
        for(i = 0; i < size;i++)
        {
        	if(s[i] == '(')
        	{
        		left ++;
        		flag.push_back(i);
        	}
        	else
        	{
        		if(left > 0)
        		{
        			left --;
        			flag.pop_back();
        		}
        		else
        		{
					flag.push_back(i);
        		}
        	}
        }
        flag.push_back(size);
        for(i = 1;i < flag.size();i++)
        {
        	tmp = flag[i] - flag[i-1] - 1;
        	if(tmp > maxlen) maxlen = tmp;
        }
        return maxlen;
    }
};