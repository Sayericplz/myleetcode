class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        int pos[3];
        recursion(res,0,pos,0,s);
        return res;
    }

    void recursion(vector<string> &res,int step,int pos[],int i,string s)
    {
    	if(s.size()-i > 3*(4-step) || s.size()-i < 4-step)
    		return;
    	string ss;
    	if(step == 3)
    	{
    		ss = s.substr(i);
    		if(!((s.size()!=1 && ss[0] == '0') || (ss.size()==3 && ss > "255")))
    		{
    			ss = "";
				ss+= s.substr(0,pos[0])+'.';
				ss+= s.substr(pos[0],pos[1]-pos[0])+'.';
				ss+= s.substr(pos[1],pos[2]-pos[1])+'.';
				ss+= s.substr(pos[2]);
				res.push_back(ss);				
    		}
    		return;
    	}
    	ss = s.substr(i,1);
    	if(ss>="0"&&ss<="9")
    	{
    		pos[step] = i+1;
    		recursion(res,step+1,pos,i+1,s);
    	}
    	if(s.size()-i>=2)
    	{
	    	ss = s.substr(i,2);
	    	if(ss>="10"&&ss<="99")
	    	{
	    		pos[step] = i+2;
	    		recursion(res,step+1,pos,i+2,s);
	    	}
    	}
    	if(s.size()-i>=3)
    	{
	    	ss = s.substr(i,3);
	    	if(ss>="100"&&ss<="255")
	    	{
	    		pos[step] = i+3;
	    		recursion(res,step+1,pos,i+3,s);
	    	}
    	}

    }
};