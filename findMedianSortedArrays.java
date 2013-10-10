public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int k = A.length+B.length;
        if(k % 2 == 1)
            return findk(A,B,A.length,B.length,0,0,k/2+1);
        else
            return (findk(A,B,A.length,B.length,0,0,k/2+1) + findk(A,B,A.length,B.length,0,0,k/2))/2;
    }

    public double findk(int A[], int B[],int m,int n, int sa,int sb,int k)
    {
        if(m > n)
            return findk(B,A,n,m,sb,sa,k);
        if(m == 0)
            return B[sb+k-1];
        if(k == 1)
            return Math.min(A[sa],B[sb]);
        int pa = Math.min(k/2,m), pb = k-pa;
        if(A[sa+pa-1] < B[sb+pb-1])
            return findk(A,B,m-pa,n,sa+pa,sb,pb);
        else if(A[sa+pa-1] > B[sb+pb-1])
            return findk(A,B,m,n-pb,sa,sb+pb,pa);
        else
            return A[pa-1];
    }
}