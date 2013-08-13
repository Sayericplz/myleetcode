class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        solve(board);
    }

    bool solve(vector<vector<char> > &board)
    {
    	int r,c,i,j,flag = 1;
    	for(i = 0;i < 9;i++)
    	{
    		for(j = 0;j < 9;j++)
    		{
    			if(board[i][j] == '.')
    			{
    				flag = 0;
    				r = i;
    				c = j;
    				break;
    			}
    		}
    		if(flag == 0) break; 
    	}
    	if(flag) return true;
    	vector<int> conflicts;
    	for(i = 0;i < 9;i++)
    	{
    		if(board[r][i] != '.')
    			conflicts.push_back(board[r][i] - 48);
    		if(board[i][c] != '.')
    			conflicts.push_back(board[i][c] - 48);
    	}
    	int rr = r - r%3;
    	int cc = c - c%3;
    	for(i = 0;i<3;i++)
    	{
    		for(j = 0;j<3;j++)
    		{
    			if(board[i+rr][j+cc] != '.')
    				conflicts.push_back(board[i+rr][j+cc] - 48);
    		}
    	}
    	for(i = 1;i < 10;i++)
    	{
    		if(count(conflicts.begin(),conflicts.end(),i)==0)
    		{
    			board[r][c] = i + '0';
    			if(solve(board)) return true;
    			board[r][c] = '.';
    		}
    	}
    	return false;
    }
};