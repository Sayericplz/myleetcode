class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
  		int flag = 0,res = 0;
  		if(divisor == 0) return INT_MAX;
  		if(divisor == INT_MIN)
  		{
  			if(dividend == INT_MIN) return 1;
  			else return 0;
  		}
  		if(dividend == INT_MIN)
  		{
  			dividend += 1;
  			if(abs(divisor) == 1 || abs(divisor) == 2)
  			{
  				res ++;
  			}
  		}
  		if(dividend < 0)
  		{
  			dividend = -dividend;
  			flag = 1 - flag;
  		}     
  		if(divisor < 0)
  		{
  			divisor = -divisor;
  			flag = 1 - flag;
  		}
  		while(dividend >= divisor)
  		{
  			int tmp = divisor;
  			int tmpres = 1;
  			while(dividend >= tmp + tmp && tmp < 0x40000000)
  			{
  				tmp = tmp << 1;
  				tmpres = tmpres+tmpres;
  			}
			dividend -= tmp;
			res += tmpres;
  		}
  		if(flag) return -res;
  		return res;
    }
};