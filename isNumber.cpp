class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool valid = false;
        int flag = 1;
        while(1)
        {
            if(flag == 1)
        	{
        		while(*s == ' ') s++;
        		if(*s == '+' || *s == '-') s++;
        		if(*s >= '0' && *s <= '9')
        		{
        			while(*s >= '0' && *s <= '9') s++;
        			valid = true;
        		}
        		if(*s == '.')
        		{
        			flag = 2;
        			s++;
        			continue;
        		}
        		else if(*s == 'e' && valid)
        		{
        			flag = 3;
        			s++;
        			continue;
        		}
        		while(*s == ' ') s++;
        		return (valid && !(*s));
        	}
        	else if(flag == 2)
        	{
        		if(*s >= '0' && *s <= '9')
        		{
        			while(*s >= '0' && *s <= '9') s++;
        			valid = true;
        		}
        		if(*s == 'e' && valid)
        		{
        			flag = 3;
        			s++;
        			continue;
        		}
        		while(*s == ' ') s++;
        		return (valid && !(*s));
        	}
        	else
        	{
        		valid = false;
        		if(*s == '+' || *s == '-') s++;
        		if(*s >= '0' && *s <= '9')
        		{
        			while(*s >= '0' && *s <= '9') s++;
        			valid = true;
        		}
        		while(*s == ' ') s++;
        		return (valid && !(*s));
        	}
        }
    }
};