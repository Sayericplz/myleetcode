public class Solution {
    public String convert(String s, int nRows) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if(nRows <= 1) return s;
        String res = "";
        int total = (nRows-1) * 2, len = s.length();
        for(int i = 0;i < nRows;i++)
        {
        	int step = (nRows-1-i)*2;
        	int j = i;
        	while(j < len)
        	{
        		res += s.charAt(j);
        		if(step == 0) step = total;
        		j += step;
        		step = total - step;
        	}
        }
        return res;
    }
}