class Solution {
public:
	string d2="abc";
	string d3="def";
	string d4="ghi";
	string d5="jkl";
	string d6="mno";
	string d7="pqrs";
	string d8="tuv";
	string d9="wxyz";
	vector<string> res;
	string tmp;

    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if(digits.size() == 0)
        {
        	res.push_back("");
        	return res;
        }
        tmp = string(digits.size(),'a');
        getResult(digits,0);
        //vector<string>::const_iterator lookfor = find(res.begin(),res.end(),"");
        //if(lookfor != res.end()) res.erase(lookfor);
        return res;
    }

    void getResult(string s,int pos)
    {
    	string current;
    	if(pos == s.size())
    	{
    		res.push_back(tmp);
    	}
    	else
    	{
    		switch(s[pos])
    		{
    			case '2':current = d2;break;
    			case '3':current = d3;break;
    			case '4':current = d4;break;
    			case '5':current = d5;break;
    			case '6':current = d6;break;
    			case '7':current = d7;break;
    			case '8':current = d8;break;
    			case '9':current = d9;break;
    		}
    		for(int i = 0;i < current.size();i ++)
    		{
    			tmp[pos] = current[i];
    			getResult(s,pos+1); 
    		}
    	}
    }
};