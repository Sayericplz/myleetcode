class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s(str);
        int len = s.size();
        int res = 0;
        int pos = 0;
        double tmp = 0;
        int array[10];
        int i,flag=0,start,end;
        for(i = 0;i < 10;i++)
        {
        	array[i] = -1;
        }
        while(s[pos] == ' ' && pos < len)
        {
        	pos ++;
        }
        if(pos == len || (pos == len - 1 && !(s[pos]>='0'&&s[pos]<='9')))
        {
        	return res;
        }
        else if(s[pos] == '-')
        {	
        	flag = 1; 
        	pos ++;
        }
        else if(s[pos] == '+')
        {
        	pos++;
        }
        if(!(s[pos]>='0'&&s[pos]<='9'))
        {
        	return res;
        }
        start = pos;
        while(s[pos]>='0'&&s[pos]<='9' && pos < len)
        {
        	pos ++;
        }
        end = pos - 1;
        if(end-start+1 > 10)
        {
        	if(flag == 1)
        	{
        		return INT_MIN;
        	}
        	else
        	{
        		return INT_MAX;
        	}
        }
        for(i = start; i < end+1;i++ )
        {
        	array[i-start]=s[i]-48;
        }
        for(i=0;i<10;i++)
        {
        	if(array[i] == -1)
        	{
        		break;
        	}
        	tmp = tmp*10 + array[i];
        }
        if(tmp > INT_MAX)
        {
        	if(flag == 1)
        	{
        		return INT_MIN;
        	}
        	else
        	{
        		return INT_MAX;
        	}
        }
        if(flag == 1)
        {
        	return -(int)tmp;
        }
        return (int)tmp;
    }
};