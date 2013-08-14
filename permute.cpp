class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > res;
        int n = num.size();
        if(n == 0) return res;
        map<int,int> counter;
        int i;
        for(i = 0;i < n;i++)
        {
            if(counter.count(num[i]) > 0)
        		counter[num[i]]++;
        	else
        		counter[num[i]] = 1;
        }
        vector<int> tmp;
        recursion(res,tmp,counter,0,n);
        return res;
    }

    void recursion(vector<vector<int> > &res, vector<int> &tmp, map<int,int> &counter,int pos,int n)
    {
    	if(pos == n)
    	{
    		res.push_back(tmp);
    		return;
    	}
    	map<int,int>::iterator p;
    	for(p = counter.begin();p != counter.end();p++)
    	{
    		if(p->second > 0)
    		{
    			tmp.push_back(p->first);
    			p->second --;
    			recursion(res,tmp,counter,pos+1,n);
    			p->second ++;
    			tmp.pop_back();
    		}
    	}
    }
};