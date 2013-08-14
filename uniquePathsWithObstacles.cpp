class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        if(m == 0) return 0;
        int n = obstacleGrid[0].size();
        if(n == 0) return 0;
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0]) return 0;
        vector<vector<int> > steps(m+1,vector<int>(n+1,0));
        steps[0][1] = 1;
        for(int i = 1;i <= m;i++)
        {
        	for(int j = 1;j <= n;j++)
        	{
        		if(obstacleGrid[i-1][j-1])
        			steps[i][j] = 0;
        		else
        			steps[i][j] = steps[i-1][j]+steps[i][j-1];
        	}
        }
        return steps[m][n];
    }
};