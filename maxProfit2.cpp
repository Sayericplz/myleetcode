class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!prices.size()) return 0;
        int max = prices[0],min = prices[0],profit = 0;
        for(int i = 1;i < prices.size();i++)
        {
        	if(prices[i] >= max)
        	{
        		max = prices[i];
        	}
        	else
        	{
        		profit += max-min;
        		max = prices[i];
        		min = prices[i];
        	}
        }
        profit += max-min;
        return profit;
    }
};