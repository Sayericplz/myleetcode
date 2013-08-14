class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res(n,vector<int>(n));
        int num = 1,begX = 0,endX = n - 1,begY = 0,endY= n - 1,i;
        while(num <= n*n)
        {
            for(i = begY;i <= endY;i++)
            {
                res[begX][i] = num++;          
            }
            begX ++;
            for(i = begX;i <= endX;i++)
            {
                res[i][endY] = num++;                
            }
            endY--;
            for(i = endY;i >= begY;i--)
            {
                res[endX][i] = num++;              
            }
            endX--;
            for(i = endX;i >= begX;i--)
            {
                res[i][begY] = num++;               
            }
            begY++;
        }
        return res;
    }
};