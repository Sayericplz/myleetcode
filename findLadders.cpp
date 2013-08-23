class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        vector<string> sdict;
        unordered_map<string,int> id;
        int len = start.size();
        for(unordered_set<string>::iterator i = dict.begin();i != dict.end();i++)
        {
            id[*i] = sdict.size();
        	sdict.push_back(*i);
        }
        int n = sdict.size();
        vector<vector<int> > adj(n);
        for(int i = 0;i < sdict.size();i++)
        {
        	string s = sdict[i];
        	for(int j = 0;j < len;j++)
        	{       		
        		for(char c = 'a'; c <= 'z';c++)
        		{
        			if(c != sdict[i][j])
        			{
        				s[j] = c;
        				if(id.count(s))
        				{
        					adj[i].push_back(id[s]);
        				}
        				s[j] = sdict[i][j];
        			}
        		}
        	}
        }
        id.clear();
        int sno,eno;
        for(int i = 0;i < sdict.size();i++)
        {
        	if(sdict[i] == start)
        	{
        		sno = i;
        		break;
        	}
        }
        for(int i = 0;i < sdict.size();i++)
        {
        	if(sdict[i] == end)
        	{
        		eno = i;
        		break;
        	}
        }
        queue<int> q;
        vector<int> dis(n);
        dis[sno] = 0;
        vector<vector<int> > pre(n);
        vector<bool> visit(n,false);
        visit[sno] = true;
        q.push(sno);
        while(!q.empty())
        {
        	int cur = q.front();
        	q.pop();
        	if(cur == eno) break;
        	//visit[cur] = true;
        	int d = dis[cur] + 1;
        	for(int i = 0;i < adj[cur].size();i++)
        	{
        		int next = adj[cur][i];
        		if(!visit[next])
        		{
        			visit[next] = true;
        			q.push(next);
        			dis[next] = d;
        			pre[next].push_back(cur);
        		}
        		else if(dis[next] == d)
        		{
        			pre[next].push_back(cur);
        		}
        	}
        }
        //q.clear();
        visit.clear();
        adj.clear();
        dis.clear();
        vector<vector<string> > res;
        vector<int> path;
        generate(res,sdict,path,pre,sno,eno);
        return res;
    }

    void generate(vector<vector<string> > &res,vector<string> &sdict,vector<int> &path,vector<vector<int> > &pre,int sno,int eno)
    {
    	path.push_back(eno);
    	if(eno == sno)
    	{
    		res.push_back(vector<string>());
    		for(int i = path.size()-1;i >= 0;i--)
    			res.back().push_back(sdict[path[i]]);
    	} 
    	else
    	{   	
	    	for(int i = 0;i < pre[eno].size();i++)
	    	{
	    		generate(res,sdict,path,pre,sno,pre[eno][i]);
	    	}
	    }
    	path.pop_back();
    }
};