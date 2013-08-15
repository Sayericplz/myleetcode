class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = 1;
        while(n*n <= x && n*n > 0) n++;
        return n-1;
    }
};