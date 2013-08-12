class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() <= 1) return;
        int left = -1,n = num.size(),i,j,tmp;
        int right = n-1;
        for(i = n-2;i>=0;i--)
        {
        	int min=INT_MAX;
        	int flag = 0;
        	for(j = i+1;j<n;j++)
        	{
        		if(num[j]>num[i] && num[j]<=min)
        		{
        			min = num[j];
        			right = j;
        			left = i;
        			flag = 1;
        		}
        	}
        	if(flag) break;
        }
        if(left != -1) swap(num[left],num[right]);
        for(i = left+1,j = n-1;i<j;i++,j--)
        {
        	swap(num[i],num[j]);
        }
    }

    void swap(int &x,int &y)
    {
    	int tmp = x;
    	x = y;
    	y = tmp;
    }
};