class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	vector<int> res;
    	int i,j;
    	if(L.size() == 0 || L[0].size() == 0 || S.size() == 0)
    	{
    		for(i = 0; i < S.size();i++) res.push_back(i);
    		return res;
    	}
    	map<string,int> index;
    	int n = L.size();
    	int count[n];
    	int num = 0;
    	for(i = 0;i < n;i++)
    	{
    		if(index.count(L[i]) > 0)
    		{
    			count[index[L[i]]] ++;
    		}
    		else
    		{
    			index[L[i]] = num;
    			count[num++] = 1;
    		}
    	}
    	vector<int> flag;
    	int size = L[0].size();
    	for(i = 0; i < size;i++)
    	{
    		flag.clear();
    		for(j = i; j < S.size();j+=size)
    		{
    			if(j + size<= S.size())
    			{
    				string ss = S.substr(j,size);
    				if(index.count(ss) > 0)
    				{
    					flag.push_back(index[ss]);
    				}
    				else
    				{
    					flag.push_back(-1);
    				}
    			}
    		}
    		int beg = -1;
    		int end = 0;
    		while(end < flag.size())
    		{
    			if(flag[end] != -1)
    			{
    				if(count[flag[end]] > 0 )
    				{
    					if(beg == -1) beg = end;
    					n--;
    					count[flag[end]]--;
    				}
    				else
    				{
    					while(beg < end)
    					{
    						n++;
    						count[flag[beg]]++;
    						if(flag[beg++] == flag[end]) break;
    					}
    					n --;
    					count[flag[end]]--;
    				}
    			}
    			else
    			{
    				if(beg != -1)
    				{
    					while(beg < end)
    					{
    						n++;
    						count[flag[beg++]]++;
    					}
    					beg = -1;
    				}
    			}
    			if(n == 0) 
    			{
    				res.push_back(i + beg*size);
    				n++;
    				count[flag[beg]]++;
    				beg ++;
    			}
    			end ++;
    		}
    		n = L.size();
    		if(beg != -1)
    		{
	    		while(beg < end)
				{
					count[flag[beg++]]++;
				}
    		}
    	}
    	return res;
    }
};