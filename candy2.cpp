class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size(),sum = 0;
        if(n < 2) return n;
        int *c = new int[n];
        c[0] = 1;
        for(int i = 1;i < n;i++)
        {
            if(ratings[i] > ratings[i-1])
              c[i] = c[i-1]+1;
            else
              c[i] = 1;
        }
        for(int i = n-2;i >= 0;i--)
        {
            if(ratings[i] > ratings[i+1] && c[i+1]+1 > c[i])
              c[i] = c[i+1]+1;
        }
        for(int i = 0; i < n;i++)
            sum += c[i];
        delete []c;
        return sum;
    }
};