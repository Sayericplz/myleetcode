class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0)
        {
            while(*p != 0 && *p == '*')
            	p++;
        	return *p == 0;
        }
        if(*p == 0) return false;
        vector<int> pos;
        int i;
        if(*p == '?' || *p == *s)
        {
        	return isMatch(s+1,p+1);
        }
        else if(*p == '*')
        {
        	pos.clear();
        	int plen;
        	while(*p == '*') p++;
        	matchHelp(pos,s,p,plen);
        	for(i = 0;i < pos.size(); i++)
        	{
        		if(isMatch(s+pos[i] + plen,p + plen)) return true;
        	}
        }
        return false;
    }

    void matchHelp(vector<int> &pos,const char *s,const char *p, int &plen)
    {
    	int slen = strlen(s),i,j;
    	plen = 0;
    	while(*(p+plen) != 0 && *(p+plen) != '*')
    		plen++;
    	for(i = 0; i <= slen - plen;i++)
    	{
    		for(j = i;j < i+plen;j++)
    		{
    			if(*(s+j) != *(p+j-i) && *(p+j-i) != '?')
    				break;
    		}
    		if(j == i+plen+1) pos.push_back(i);
    	}
    }
};