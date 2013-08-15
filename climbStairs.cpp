class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1) return 0;
        int *step = new int[n+1];
        step[0] = 1;
        step[1] = 1;
        for(int i = 2;i <= n;i++)
        	step[i] = step[i-1] + step[i-2];
        int res = step[n];
        delete []step;
        return step[n];
    }
};