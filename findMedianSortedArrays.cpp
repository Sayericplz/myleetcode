class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *C = new int[m+n];
        double median;
        int i=0;
        int j=0;
        int k=0;
        while(k!=m+n)
        {
        	if(i==m)
        	{
        		C[k++]=B[j++];
        	}
        	else if(j==n)
        	{
        		C[k++]=A[i++];
        	}
        	else
        	{
        		if(A[i] < B[j])
        		{
        			C[k++]=A[i++];
        		}
        		else
        		{
        			C[k++]=B[j++];
        		}
        	}
        }
        int k = (m+n)/2;
        if((m+n)%2==0)
        {
        	median = ((double)(C[k-1]+C[k]))/2;
        }
        else
        {
        	median = C[k];
        }
        delete []C;
        return median;
    }
};