class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        if(n == 0) return 0;
        int *B = new int[n];
        B[0] = A[0];
        for(int i = 1;i < n;i++)
        {
        	B[i] = B[i-1] < 0? A[i]:B[i-1]+A[i];
        	if(B[i] > max) max = B[i];
        }
        return max;
    }
};