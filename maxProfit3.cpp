class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!prices.size()) return 0;
        int n = prices.size();
        vector<int> p1(n,0);
        vector<int> p2(n,0);	
        int tmp = prices[0];
        for(int i = 1;i < n;i++)
        {
        	tmp = min(prices[i],tmp);
        	p1[i] = max(prices[i] - tmp,p1[i-1]);
        }
        tmp = prices[n-1];
        for(int i = n-2;i >= 0;i--)
        {
        	tmp = max(prices[i],tmp);
        	p2[i] = max(tmp - prices[i],p2[i+1]);
        }
        int profit = 0;
        for(int i = 0; i < n;i++)
        {
        	if(p1[i]+p2[i]>profit)
        		profit = p1[i]+p2[i];
        }
        return profit;
    }
};