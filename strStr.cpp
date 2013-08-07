class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*haystack == 0 && *needle != 0) return NULL;
        if(*needle == 0) return haystack;
        int len1 = strlen(haystack);
        int len2 = strlen(needle);
        int i,j,k;
        for(i = 0;i <= len1-len2;i++)
        {
        	k = 0;
        	if(haystack[i] == needle[k])
        	{
        		j = i+1;
        		k = 1;
        		while(j != len1 && k != len2 && haystack[j]==needle[k])
        		{
        			j++;
        			k++;
        		}
        		if(k == len2) return haystack + i;
        	}
        }
        return NULL;
    }
};