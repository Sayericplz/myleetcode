class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxl = 1;
        map<int,int> map;
        for(int i = 0;i < num.size();i++)
        {
        	if(map.find(num[i]) != map.end())
        		continue;
        	map[num[i]] = 1;
        	if(map.find(num[i]+1) != map.end())
        	{
        		int range = map[num[i]+1];
        		map[num[i]+range] = range+1;
        		map[num[i]] = range+1;
        		if(range+1>maxl) maxl = range+1;
        	}
        	if(map.find(num[i]-1) != map.end())
        	{
        		int range1 = map[num[i]];
        		int range2 = map[num[i]-1];
        		map[num[i]+range1-1] = range1+range2;
        		map[num[i]-range2] = range1+range2;
        		if(range1+range2>maxl) maxl = range1+range2;
        	}
        }
        return maxl;
    }
};