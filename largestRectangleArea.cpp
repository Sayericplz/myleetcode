class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> s;
        int i = 0,max = 0;
        height.push_back(0);
        while(i < height.size())
        {
        	if(s.empty() || height[s.back()] <= height[i])
        	{
        		s.push_back(i++);
        	}
        	else
        	{
        		int h = height[s.back()];
        		s.pop_back();
        		int len;
        		if(s.empty()) len = i;
        		else len = i - s.back() - 1;
        		if(h*len > max) max = h*len;
        	}
        }
        return max;
    }
};