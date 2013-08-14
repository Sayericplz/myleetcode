class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0 || x == 1) return 1;
        if(x == 0) return 0;
        if(x == -1)
        {
        	if(n%2) return -1;
        	else return 1;
        }
        bool neg = false;
        double res = 1;
        double tmp = 1;
        if(n < 0 ) 
        {
        	neg = true;
        	n = -n;
        }
        while(n > 0)
        {
        	tmp = res;
        	res *= x;
        	if(abs(res)<0.000001)
        	{
        		res = 0;
        		break;
        	}
        	n--;
        }
        if(neg) res = 1/res;
        return res;
    }
};