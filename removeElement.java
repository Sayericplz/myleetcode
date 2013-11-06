public class Solution {
    public int removeElement(int[] A, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = A.length - 1,i = 0;
        while(n >= 0 && A[n] == elem)
        	n--;
        while(i < n)
        {
        	if(A[i] == elem)
        	{
        		int tmp = A[i];
        		A[i] = A[n];
        		A[n--] = tmp;
        		while(n >= 0 && A[n] == elem)
        			n--;
        	}
        	i++;
        }
        return n+1;
    }
}