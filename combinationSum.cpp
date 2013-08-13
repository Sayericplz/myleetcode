class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        vector<int> tmp;
        getResult(res,tmp,candidates,0,target);
        for(int i = 0;i < res.size();i++)
        {
        	sort(res[i].begin(),res[i].end());
        }
        return res;
    }

    void getResult(vector<vector<int> > &res,vector<int> &tmp, vector<int> &candidates,int pos,int target)
    {
    	if(target == 0)
    	{
    		res.push_back(tmp);
    		return;
    	}
    	if(pos == candidates.size()) return;
    	int times = target / candidates[pos];
    	int i,j,num = candidates[pos];
    	for(i = 0;i <= times;i++)
    	{
    		for(j = 0; j < i;j ++) tmp.push_back(num);
    		getResult(res,tmp,candidates,pos+1,target - i*num);
    		for(j = 0; j < i;j ++) tmp.pop_back();
    	}  
    }
};