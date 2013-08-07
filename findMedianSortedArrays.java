public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int m = A.length;
        int n = B.length;
        int C[] = new int[m+n];
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
        k = (m+n)/2;
        if((m+n)%2==0)
        {
        	median = ((double)(C[k-1]+C[k]))/2;
        }
        else
        {
        	median = C[k];
        }
        return median;
    }
}