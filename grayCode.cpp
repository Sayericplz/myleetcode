class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(0);
        for(int i = 1; i <= n;i++)
        {
            int len = res.size();
        	for(int j = len-1; j>=0;j--)
        		res.push_back(res[j]+len);
        }
        return res;
    }
};