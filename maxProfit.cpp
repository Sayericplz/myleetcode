class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!prices.size()) return 0;
        int max = prices[0],min = prices[0],profit = 0;
        for(int i = 1;i < prices.size()-1;i++)
        {
			if(prices[i] > max)
			{
				if(prices[i] - min > profit)
					profit = prices[i] - min;
				max = prices[i];
			}
			else if(prices[i] < min)
			{
				min = prices[i];
				max = prices[i];
			}
        }
        return profit;
    }
};