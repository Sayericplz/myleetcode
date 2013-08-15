class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        vector<vector<int> > min(m+1,vector<int>(n+1,INT_MAX));
        min[0][1] = 0;
        for(int i = 1;i <= m;i++)
        {
        	for(int j = 1;j <= n;j++)
        	{
        		min[i][j] = (min[i-1][j]<min[i][j-1]?min[i-1][j]:min[i][j-1]) + grid[i-1][j-1];
        	}
        }
        return min[m][n];
    }
};