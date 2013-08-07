class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size();
        if(n == 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return 1;
        }
        int len = 0;
        int maxlen = 0;
        set<char> chars;
        int i ,j;
        for(i = 0;i < n-1;i++)
        {
            chars.insert(s[i]);
        	len = 1;
        	for(j = i+1; j < n;j++)
        	{
        		if(chars.count(s[j]))
        		{
        			if(len > maxlen)
        			{
        				maxlen = len;
        			}
        			break;
        		}
        		else
        		{
        			chars.insert(s[j]);
        			len++;
        		}
        	}
            if(j == n && len > maxlen)
            {
                maxlen = len;
            }
        	chars.clear();
        }
        return maxlen;
    }
};