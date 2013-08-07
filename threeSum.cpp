class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    vector<vector<int> > res;
    if(num.size() == 0) return res;
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
    		if(sum > 0)
    		{
    			k--;
    		}
    		else if(sum < 0)
    		{
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
    			vector<int> tmp;
    			tmp.push_back(*i);
    			tmp.push_back(*j);
    			tmp.push_back(*k);
    			res.push_back(tmp);
    			j++;
    			k--;
    		}
    	}
    }
    return res;
}
};