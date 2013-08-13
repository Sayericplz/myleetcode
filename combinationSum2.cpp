class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> tmp;
        getResult(res,tmp,num,0,target);
        return res;
    }

    void getResult(vector<vector<int> > &res,vector<int> &tmp, vector<int> &candidates,int pos,int target)
    {
    	if(target == 0)
    	{
    		vector<int> sortedtmp(tmp);
    		sort(sortedtmp.begin(),sortedtmp.end());
    		if(count(res.begin(),res.end(),sortedtmp) == 0)
    			res.push_back(sortedtmp);
    		return;
    	}
    	if(pos == candidates.size()) return;
    	int num = candidates[pos];
    	if(num <= target)
    	{
    		tmp.push_back(num);
    		getResult(res,tmp,candidates,pos+1,target - num);
    		tmp.pop_back();
    	}  
    	getResult(res,tmp,candidates,pos+1,target);
    }
};