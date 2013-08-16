class Solution {
public:
     bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return false;
        int l = 0, r = n-1;
        if(A[l] == A[r])
        {
        	if(A[l] == target) return true;
        	while(r >= l && A[r] == A[l]) r--;
        }
        while(l <= r)
        {
        	int mid = (l+r)/2;
        	if(A[mid] == target) return true;
        	if(A[mid] >= A[l])
        	{
        		if(A[mid] > target && A[l] <= target)
        			r = mid - 1;
        		else
        			l = mid + 1;
        	}
        	else
        	{
        		if(A[mid] < target && A[r] >= target)
        			l = mid + 1;
        		else
        			r = mid - 1;
        	}
        }
        return false;
    }
};