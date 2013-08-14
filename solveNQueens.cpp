class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > res;
        if(n < 1) return res;
        vector<string> tmp;
        string s(n,'.');
        for(int i = 0;i < n;i++) tmp.push_back(s);
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
        recursion(res,tmp,0,col,ld,rd,n);
        return res;
    }

    void recursion(vector<vector<string> > &res, vector<string> &tmp, int row,bool *col,bool *ld,bool *rd,int n)
    {
    	if(row == n)
    	{
    		res.push_back(tmp);
    		return;
    	}
    	for(int i = 0; i < n;i++)
    	{
    		if(col[i] && ld[i+row] && rd[n-1-row+i])
    		{
    			tmp[row][i] = 'Q';
    			col[i] = false;
    			ld[i+row] = false;
    			rd[n-1-row+i] = false;
    			recursion(res,tmp,row+1,col,ld,rd,n);
    			rd[n-1-row+i] = true;
    			ld[i+row] = true;
    			col[i] = true;
    			tmp[row][i] = '.';
    		}
    	}
    }
};