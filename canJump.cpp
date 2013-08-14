class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1) return true;
        int i,start = 0,end=0;
        while(end < n-1)
        {
        	int max = 0;
        	for(i = start;i <= end;i++)
        	{
        		if(A[i] + i> max) max = A[i]+i;
        	}        
        	if(max == end) return false;	
        	start = end+1;
        	end = max;
        }
        return true;
    }
};