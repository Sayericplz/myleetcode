class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pos = -1,i,j,res=-1;
        if(n == 0) return res;
        for(i = 0;i<n-1;i++)
        {
        	if(A[i+1]<A[i])
        	{
        		pos = i;
        		break;
        	}
        }
        int B[n];
        for(i = pos+1;i<n;i++) B[i-pos-1]=A[i];
        for(i=0;i<=pos;i++) B[i+n-pos-1]=A[i];
        i = 0;
        j=n-1;
        while(i<=j)
        {
        	int mid = (i+j)/2;
        	if(B[mid] == target)
        	{
        		res = mid;
        		break;
        	}
        	else if(B[mid] > target)
        	{
        		j = mid-1;
        	}
        	else
        	{
        		i = mid+1;
        	}
        }
        if(res == -1) return -1;
        if(res < n-pos-1) return res+pos+1;
        else return res-n+pos+1;
    }
};