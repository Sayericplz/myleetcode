class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int start = 0,pos = 0,end = n-1;
        while(pos <= end)
        {
            int tmp;
        	if(A[pos] == 0)
        	{
        		tmp = A[pos];
        		A[pos] = A[start];
        		A[start++] = tmp;
                pos = start;
        	}
        	else if(A[pos] == 2)
        	{
        		tmp = A[pos];
        		A[pos] = A[end];
        		A[end--] = tmp;
        	}
            else if(A[pos] == 1)
            {
        		pos++;
            }
        }
        return;
    }
};