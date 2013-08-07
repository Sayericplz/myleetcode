class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
	    if(num.size() == 0) return res;
	    sort(num.begin(),num.end());
	    
	    for(vector<int>::const_iterator i = num.begin();i<num.end()-3;i++)
	    {
	    	if(i>num.begin()&&*i==*(i-1))
	    		continue;
	    	for(vector<int>::const_iterator l = num.end()-1; l>i+2;l--)
	    	{
	    		if(l<num.end()-1&&*l==*(l+1))
	    			continue;
		    	vector<int>::const_iterator j,k;
		    	j = i+1;
		    	k = l-1;
		    	while(j<k)
		    	{
		    		int sum = *i+*j+*k+*l;
		    		if(sum > target)
		    		{
		    			k--;
		    		}
		    		else if(sum < target)
		    		{
		    			j++;
		    		}
		    		else if(j>i+1 && *j==*(j-1))
		    		{
		    			j++;
		    		}
		    		else if(k<l-1 && *k==*(k+1))
		    		{
		    			k--;
		    		}
		    		else
		    		{
		    			vector<int> tmp;
		    			tmp.push_back(*i);
		    			tmp.push_back(*j);
		    			tmp.push_back(*k);
		    			tmp.push_back(*l);
		    			res.push_back(tmp);
		    			j++;
		    			k--;
		    		}
		    	}
	    	}
	    }
	    return res;
    }
};