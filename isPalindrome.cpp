class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int base = 0;
        int left,right,tmp,i;
        if (x < 0)
        {
        	return false;
        }
        tmp = x;
        while(tmp > 9)
        {
        	base ++;
        	tmp /= 10;
        }
        while(x > 9)
        {
        	tmp = (int)pow(10,base);
        	right = x % 10;
        	left = x/tmp;
        	if(left != right) return false;
        	x -= tmp * left;
        	x /= 10;
        	base -= 2;
        }
        return true;
    }
};