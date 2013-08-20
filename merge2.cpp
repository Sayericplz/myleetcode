class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!n) return;
        if(!m)
        {
        	for(int i = 0;i < n;i++)
        	{
        		A[i] = B[i];
        	}
        }
        int p = 0,q = 0;
        while(q < n)
        {
        	while(p < m && B[q] >= A[p+q]) p++;
        	for(int i = m-1+q;i >= p+q;i--)
        	{
        		A[i+1] = A[i];
        	}
        	A[p+q] = B[q++];
        }
    }
};