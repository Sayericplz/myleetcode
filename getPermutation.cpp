class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0) return "";
        int *div = new int[n];
        div[0] = 1;
        vector<int> num;
        num.push_back(1);
        for(int i = 1;i < n;i++)
        {
            div[i] = div[i-1] * (i+1);
        	num.push_back(i+1);
        }
        if(k < 1 || k > div[n-1]) return "";
        k = k-1;
        string s(n,' ');
        for(int i = n-2;i >= 0;i--)
        {
        	s[n-2-i] = num[k/div[i]]+'0';
        	vector<int>::iterator p = num.begin()+k/div[i];
        	num.erase(p);
        	k = k%div[i];       	
        }
        s[n-1] = num[0]+'0';
        delete []div;
        return s;
    }
};