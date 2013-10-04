class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> arr;
        int n = gas.size();
        for(int i = 0;i < n;i++)
        	arr.push_back(gas[i]-cost[i]);
        for(int i = 0;i < n;i++)
        	arr.push_back(arr[i]);
        int start = 0,pos = 0,sum = 0;
        while(start < n)
        {
        	while(pos-start < n && sum >= 0)
        		sum += arr[pos++];
        	if(sum < 0)
        	{
        		start = pos;
        		sum = 0;
        	}
        	else
        		return start;
        }
        return -1;
    }
};