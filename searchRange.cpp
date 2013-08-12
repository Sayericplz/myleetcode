class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(2,-1);
        if(n == 0 || A[0] > target || A[n-1] < target) return res;
        int left = 0,right = n-1,mid,beg,end,flag = 0;
        while(left <= right)
        {
        	mid = (left + right)/2;
        	if(A[mid] == target)
        	{
        		flag =1;
        		break;
        	}
        	else if(A[mid] > target) right = mid-1;
        	else left = mid+1;
        }
        if(flag)
        {
        	beg = mid;
        	end = mid;
        	while(beg >= left && A[beg] == target) beg--;
        	while(end <= right && A[end] == target)  end++;
        	res[0] = beg + 1;
        	res[1] = end - 1;  
        }
        return res;
    }
};