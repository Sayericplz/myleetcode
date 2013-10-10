public class Solution {
    public String longestPalindrome(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = s.length();
        if(len == 0) return null;
        String res = "";
        for(int i = 0;i < len;i++)
        {
        	String tmp = findPal(s,i,i);
        	if(tmp.length() > res.length()) res = tmp;
        	tmp = findPal(s,i,i+1);
        	if(tmp.length() > res.length()) res = tmp;
        }
        return res;
    }

    public String findPal(String s, int start,int end)
    {
    	int len = s.length();
    	if(end == len || (start != end && s.charAt(start) != s.charAt(end))) return "";
    	while(start >= 0 && end < len && s.charAt(start) == s.charAt(end))
    	{
    		start--;
    		end ++;
    	}
    	return s.substring(start+1,end);
    }
}