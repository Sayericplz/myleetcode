class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 1) return 0;
        int i,step=0,start = 0,end=0;
        while(end < n-1)
        {
        	int max = 0;
        	for(i = start;i <= end;i++)
        	{
        		if(A[i] + i> max) max = A[i]+i;
        	}        	
        	start = end+1;
        	end = max;
        	step ++;
        }
        return step;
    }
};
