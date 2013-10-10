public class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = s.length();
        if(len <= 1) return len;
        Set<Character> set = new HashSet<Character>();
        set.add(s.charAt(0));
        int left = 0;
        int maxlen = 0;
        for(int i = 1;i < len;i++)
        {
        	if(set.contains(s.charAt(i)))
        	{
        		if(i - left > maxlen)
        			maxlen = i - left;
        		while(s.charAt(left) != s.charAt(i))
        		{
        			set.remove(s.charAt(left));
        			left++;
        		}
        		left++;
        	}
        	else
        		set.add(s.charAt(i));
        }
        if(set.size() > maxlen ) maxlen = set.size();
        return maxlen;
    }
}