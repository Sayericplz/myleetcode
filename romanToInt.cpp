class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        for(int pos=0;pos<s.size();pos++)
        {
        	switch(s[pos])
        	{
        		case 'M':res+=1000;break;
        		case 'D':res+=500;break;
        		case 'C':
        		{
        			switch(s[pos+1])
        			{
        				case 'M':res+=900;pos++;break;
        				case 'D':res+=400;pos++;break;
        				default:res+=100;break;
        			}
        			break;
        		}
        		case 'L':res+=50;break;
        		case 'X':
        		{
        			switch(s[pos+1])
        			{
        				case 'C':res+=90;pos++;break;
        				case 'L':res+=40;pos++;break;
        				default:res+=10;break;
        			}
        			break;
        		}
        		case 'V':res+=5;break;
        		case 'I':
        		{
        			switch(s[pos+1])
        			{
        				case 'X':res+=9;pos++;break;
        				case 'V':res+=4;pos++;break;
        				default:res+=1;break;
        			}
        			break;
        		}
        	}
        }
        return res;
    }
};