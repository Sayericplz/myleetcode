class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1) return "";
        string s = "1";
        string q = "";
        for(int i = 1; i < n;i++)
        {
        	q = s;
        	s = "";
        	for(int j = 0;j < q.size();)
        	{
        		char ch = q[j];
        		int cnt = 0;
        		while(j < q.size() && q[j] == ch)
        		{
        			cnt ++;
        			j++;
        		}
        		s += cnt+'0'; 
        		s +=ch;
        	}
        }
        return s;
    }
};