class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m == 0 || n == 0) return 0;
        if(m + n == 1) return 1;
        int y = m-1+n-1;
        int x = m<n?m-1:n-1;
        double dend = 1,div = 1;
        for(int i = 0;i < x;i++)
        {
            dend *= y-i;
        	div *= i+1;
        }
        return dend/div;
    }
};