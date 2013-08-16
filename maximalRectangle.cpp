class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n) return 0;
        vector<int> L(n);
        vector<int> R(n,n);
        vector<int> H(n);
        int max = 0;
        for(int i = 0;i < m;i++)
        {
            int left = 0,right = n;
            for(int j = 0;j < n;j++)
            {
                if(matrix[i][j] == '1')
                {
                    H[j]++;
                    if(left > L[j]) L[j] = left;
                }
                else
                {
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = n;
                    left = j + 1;
                }
            }
            for(int j = n-1;j >= 0;j--)
            {
                if(matrix[i][j] == '1')
                {
                    if(right < R[j]) R[j] = right;
                    int a = H[j]*(R[j]-L[j]);
                    if(a > max)
                    {
                         max = a;
                    }
                }
                else
                {
                    right = j;
                }
            }
        }
        return max;
    }
};