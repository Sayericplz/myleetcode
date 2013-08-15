class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        int i = 0,j = m*n-1;
        while(i<=j)
        {
        	int mid = (i+j)/2;
        	int v = matrix[mid/n][mid%n];
        	if(v == target)
        		return true;
        	else if(v > target)
        		j = mid-1;
        	else
        		i = mid+1;
        }
        return false;
    }
};