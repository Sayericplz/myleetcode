class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *flag = new int[n+1];
        int i;
        for(i = 0;i < n;i++) flag[i+1] = 0;
        for(i = 0;i < n;i++)
        {
        	if(A[i] > 0 && A[i] <= n)
        		flag[A[i]] = 1;
        }
        for(i = 1; i <= n; i++)
        {
        	if(flag[i] == 0)
        		break;
        }
        delete []flag;
        return i;
    }
};