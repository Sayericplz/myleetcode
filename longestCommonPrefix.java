public class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = strs.length;
        if(len == 0) return "";
        if(len == 1) return strs[0];
        String res = strs[0];
        int k = 0;
        while(k < res.length())
        {
        	char c = res.charAt(k);
        	for(int i = 1;i < len;i++)
        	{
        		if(k == strs[i].length())
        			return res.substring(0,k);
        		if(c != strs[i].charAt(k))
        			return res.substring(0,k);
        	}
        	k++;
        }
        return res.substring(0,k);
    }
}