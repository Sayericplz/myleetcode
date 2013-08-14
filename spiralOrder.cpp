class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        int m = matrix.size();
        if(m == 0) return res;
        int n = matrix[0].size();
        if(n == 0) return res;
        vector<vector<bool> > flag(m,vector<bool>(n,true));
        int i = 0,j = 0;
        int dir = 1,cnt = m*n-1;
        flag[i][j] = false;
        res.push_back(matrix[i][j]);
        while(cnt)
        {        	
            if(dir == 1)
            {
            	if(j < n - 1 && flag[i][j + 1])   
        			j++;
        		else
        		{
        			dir = 2;
        			continue;
        		}        		
            }
            if(dir == 2)
            {
            	if(i < m - 1 && flag[i + 1][j])   
        			i++;
        		else
        		{
        			dir = 3;       		
        			continue;
        		}
            }
            if(dir == 3)
            {
            	if(j > 0 && flag[i][j - 1])   
        			j--;
        		else
        		{
        			dir = 4;
        			continue;
        		}        		
            }
            if(dir == 4)
            {
            	if(i > 0 && flag[i - 1][j])   
        			i--;
        		else
        		{
        			dir = 1;
        			continue;
        		}
            }
            cnt -- ;  
            flag[i][j] = false;
       		res.push_back(matrix[i][j]);      	
        }
        return res;
    }
};