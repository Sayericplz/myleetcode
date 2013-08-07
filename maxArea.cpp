class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int max = 0;
    	int tmp = 0;
    	int i = 0,j = height.size()-1,h;
    	while(i < j)
    	{
    		h = height[i]>height[j]?height[j]:height[i];
    		tmp = (j-i)*h;
    		if(tmp > max) max = tmp;
    		if(height[i] > height[j]) j--;
    		else i++;
    	}
    }
};