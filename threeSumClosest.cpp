class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > res;
    int ret=0,d=INT_MAX;
    if(num.size() == 0) return ret;
    sort(num.begin(),num.end());   
    for(vector<int>::const_iterator i = num.begin();i<num.end()-2;i++)
    {
    	if(i>num.begin()&&*i==*(i-1))
    		continue;
    	vector<int>::const_iterator j,k;
    	j = i+1;
    	k = num.end()-1;
    	while(j<k)
    	{
    		int sum = *i+*j+*k;
    		if(sum > target)
    		{
    			if(sum-target < d)
    			{
    				d = sum-target;
    				ret =sum;
    			}
    			k--;
    		}
    		else if(sum < target)
    		{
    			if(target - sum < d)
    			{
    				d = target - sum;
    				ret = sum;
    			}
    			j++;
    		}
    		else if(j>i+1 && *j==*(j-1))
    		{
    			j++;
    		}
    		else if(k<num.end()-1 && *k==*(k+1))
    		{
    			k--;
    		}
    		else
    		{
    			return target;
    		}
    	}
    }
    return ret;
    }
};