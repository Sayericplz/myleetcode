class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int flag = 0,res = 0;
        if(x < 0)
        {
        	x = -x;
        	flag = 1;
        }
        int array[10];
        int pos = 0,i;
        for(i = 0;i < 10;i++)
        {
        	array[i] = -1;
        }
        while(x)
        {	
        	array[pos] = x % 10;
        	x = x/10;
        	pos++;
        }
        for(i = 0; i < 10;i++)
        {
        	if(array[i] == -1)
        	{
        		break;
        	}
        	res = 10*res + array[i];
        }
        if(flag)
        {
        	res = -res;
        }
        return res;
    }
};