class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int flag[32] = {0};
        for(int i = 0;i < n;i++)
        {
        	int tmp = A[i],j = 0;
        	for(j = 0;j < 32;j++)
        	{
        		flag[j] += tmp&1;
        		tmp >>= 1;
        	}
        }
        int res = 0;
        for(int i = 31;i >= 0;i--) 
        {
        	flag[i] %= 3;
        	res = (res<<1) + flag[i];
        }
        return res;
    }
};