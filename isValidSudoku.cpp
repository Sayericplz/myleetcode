class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,k,l,m;
        int flag[9] = {0};
        int toi;
        for(i = 0;i < 9;i++)
        {
            for(j = 0; j < 9;j++) flag[j] = 0;
        	for(j = 0; j < 9;j++)
        	{
        		if(board[i][j] >='1'&&board[i][j]<='9')
        		{
        			toi = board[i][j] - 48 - 1;
        			if(flag[toi] != 0)
        			{
        				return false;
        			}
        			else
        			{
        				flag[toi] = 1;
        			}
        		}
        	}
        }
        for(i = 0;i < 9;i++)
        {
        	for(j = 0; j < 9;j++) flag[j] = 0;
        	for(j = 0; j < 9;j++)
        	{
        		if(board[j][i] >='1'&&board[j][i]<='9')
        		{
        			toi = board[j][i] - 48 - 1;
        			if(flag[toi] != 0)
        			{
        				return false;
        			}
        			else
        			{
        				flag[toi] = 1;
        			}
        		}
        	}
        }
        for(i = 0;i < 3;i++)
        {
        	for(j = 0;j < 3;j++)
        	{
        		for(m = 0; m < 9;m++) flag[m] = 0;
        		for(k = 0; k < 3;k++)
        		{
        			for(l = 0;l < 3;l++)
        			{
        				if(board[i*3+k][j*3+l] >='1'&&board[i*3+k][j*3+l]<='9')
		        		{
		        			toi = board[i*3+k][j*3+l] - 48 - 1;
		        			if(flag[toi] != 0)
		        			{
		        				return false;
		        			}
		        			else
		        			{
		        				flag[toi] = 1;
		        			}
		        		}
        			}
        		}
        	}
        }
        return true;
    }
};