public class Solution {
    public int removeDuplicates(int[] A) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = A.length,i = 1;
        while(i < n)
        {
        	int len = 0,j = i;
        	while(j < n && A[j] == A[j-1])
        	{
        		len ++;
        		j++;
        	}
        	if(len > 0)
        	{
        		for(int k = j;k < n;k++)
        			A[i+k-j] = A[k];
        	}
        	n -= len;
        	i ++;
        }
        return n;
    }
}