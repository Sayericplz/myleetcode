class Solution {
public:
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        if(n < 1) return 0;
        bool *col = new bool[n];
        bool *ld = new bool[2*n-1];
        bool *rd = new bool[2*n-1];
        for(int i = 0;i < n;i++)
        	col[i] = true;
        for(int i = 0;i < 2*n - 1;i++)
        {
        	ld[i] = true;
        	rd[i] = true;
        }
        recursion(res,0,col,ld,rd,n);
        return res;
    }

    void recursion(int &res, int row,bool *col,bool *ld,bool *rd,int n)
    {
    	if(row == n)
    	{
    		res++;
    	}
    	for(int i = 0; i < n;i++)
    	{
    		if(col[i] && ld[i+row] && rd[n-1-row+i])
    		{
    			col[i] = false;
    			ld[i+row] = false;
    			rd[n-1-row+i] = false;
    			recursion(res,row+1,col,ld,rd,n);
    			rd[n-1-row+i] = true;
    			ld[i+row] = true;
    			col[i] = true;
    		}
    	}
    }
};