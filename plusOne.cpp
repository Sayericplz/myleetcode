class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        int size = digits.size(),adv=1;
        if(!size) return res;
        for(int i = size-1; i >= 0;i--)
        {
        	int sum = digits[i] + adv;
        	if(sum >= 10)
	       	{
	       		sum = sum - 10;
	       		adv = 1;
	       	}
	       	else
	       		adv = 0;
	       	res.push_back(sum);
        }
        if(adv) res.push_back(1);
        for(int i = 0,j = res.size()-1;i<j;i++,j--)
        {
        	int tmp = res[i];
        	res[i] = res[j];
        	res[j] = tmp;
        }
        return res;
    }
};