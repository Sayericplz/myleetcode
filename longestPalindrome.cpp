class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        string res="";
        string tmp;
        for(int i = 0;i < len;i++)
        {
        	tmp = findPal(s,i,i);
        	if(tmp.size() > res.size())
        	{
        		res = tmp;
        	}
        	tmp = findPal(s,i,i+1);
        	if(tmp.size() > res.size())
        	{
        		res = tmp;
        	}
        }
        return res;
    }

    string findPal(string s,int start,int end)
    {
    	int len = s.size();
    	if((start != end && s[start] != s[end]) || end == len)
    	{
    		return "";
    	}
    	while(start >= 0 && end < len && s[start] == s[end])
    	{
    		start--;
    		end++;
    	}
    	return s.substr(start+1,end-start-1);
    }
};