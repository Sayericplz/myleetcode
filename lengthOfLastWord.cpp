class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = 0;
        while(*s)
        {
            if(*s == ' ') s++;
        	else
        	{
        		int tmp = 0;
        		while(*s && *s!=' ')
        		{
        			tmp++;
        			s++;
        		}
        		len = tmp;
        	}
        }
        return len;
    }
};