class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = path.size();
        if(!len) return "";
        vector<string> symbol;
        int p = 0;
        while(p < len)
        {
            if(path[p] == '/') p++;
            else
        	{
        		string s="";
        		while(p < len && path[p] != '/')
        		{
        			s+=path[p];
        			p++;
        		}
        		if(s == ".") continue;
        		else if(s == "..")
        		{
        			if(!symbol.empty()) symbol.pop_back();
        		}
        		else
        			symbol.push_back(s);
        	}
        }
        string res="";
        for(int i = 0;i < symbol.size();i++)
        {
            res+="/";
        	res+= symbol[i];
        }
        if(res == "") res+="/";
        return res;
    }
};