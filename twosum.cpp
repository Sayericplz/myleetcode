class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = numbers.size();
        vector<int> index;
        for(int i = 0;i < len;i++)
        {
        	for(int j = i+1; j < len;j++)
        	{
        		if(numbers.at(i) + numbers.at(j) == target)
        		{
        			index.push_back(i+1);
        			index.push_back(j+1);
        			return index;
        		}
        	}
        }
    }
};