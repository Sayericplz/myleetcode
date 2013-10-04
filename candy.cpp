class Solution {
public:
	void recheck(int curr,int range,vector<int > &c)
	{
		int n = c.size();
		if(curr > 1)
		{
			for(int j = n-range+1;j < n;j++)
				c[j] -= curr-1; 
		}
		else if(curr < 1)
		{
			for(int j = n-range;j < n;j++)
				c[j] += 1-curr;
		}
	}

    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        if(n < 2) return n;
        int range = 1, sum = 0, curr = 1;
        bool asc,flag = false;
        vector<int> c;
       	c.push_back(1);
       	for(int i = 1;i < n;i++)
       	{
       		bool tmp;
       		if(ratings[i] == ratings[i-1])
       		{
       			if(flag && !asc) recheck(curr,range,c);
       			c.push_back(1);
       			curr = 1;
       			flag = false;
       			range = 1;
       			continue;
       		}
       		if(ratings[i] > ratings[i-1])
       		{
       			if(!flag)
       			{
       				asc = true;
       				flag = true;
       			}
       			tmp = true;
       		}
       		else
       		{
       			if(!flag)
       			{
       				asc = false;
       				flag = true;
       			}
       			tmp = false;
       		}
       		if(asc == tmp)
       		{
       			if(asc)
       				curr++;
       			else
       				curr--;
       			c.push_back(curr);
       			range++;
       		}
       		else
       		{
       			if(!asc)
       			{
       				recheck(curr,range,c);
       				curr = 2;
       			}
       			else
       				curr--;
       			c.push_back(curr);
       			asc = tmp;
       			range = 2;
       		}
       	}
       	if(!asc)
       	{
       		recheck(curr,range,c);
		}
		for(int i = 0;i < n;i++)
			sum += c[i];
		return sum;
    }
};