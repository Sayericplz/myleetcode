class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> min;
        int n = triangle.size();
        for(int i = 0;i < n;i++)
        {
        	min.push_back(triangle[n-1][i]);
        }
        for(int i = n-2;i >=0;i--)
        {
        	for(int j = 0;j <= i;j++)
        	{
        		min[j] = (min[j]<min[j+1]?min[j]:min[j+1])+triangle[i][j];
        	}
        }
        return min[0];
    }
};