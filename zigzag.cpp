class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(nRows == 1)
        {
        	return s;
        }
        int len = s.size();
        string res(s);
        int gap = nRows*2 - 2;
        int pos,step;
        int cpos = 0;
        for(int i = 0;i < nRows;i++)
        {
        	step = gap - i*2;
        	pos = i;
        	while(pos < len)
        	{
        		res[cpos++] = s[pos];
        		if(step == gap || step == 0)
        		{
        			pos += gap;
        		}
        		else
        		{
	        		pos += step;
	        		step = gap - step;        		
        		}
        	}
        }
        return res;
    }
};