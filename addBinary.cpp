class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	int lena = a.size(),lenb = b.size();
    	if(!lena) return b;
    	if(!lenb) return a;
    	if(lena < lenb)
    	{
    		string tmp = b;
    		b = a;
    		a = tmp;
    		lena = a.size();
    		lenb = b.size();
    	}
    	string s(lena+1,'0');
    	int adv = 0;
    	for(int i = lenb-1;i >= 0 ;i--)
    	{
    		int sum = adv +(a[i+lena-lenb]-48)+(b[i]-48);
    		if(sum == 1)
    		{
    			s[i+lena-lenb+1] = '1';
    			adv = 0;
    		}
    		else if(sum == 2)
    		{
    			s[i+lena-lenb+1] = '0';
    			adv = 1;
    		}
    		else if(sum == 3)
    		{
    			s[i+lena-lenb+1] = '1';
    			adv = 1;
    		}
    	}
    	for(int i = lena-lenb-1;i>=0;i--)
    	{
    		int sum = adv+(a[i]-48);
    		if(sum == 1)
    		{
    			s[i+1] = '1';
    			adv = 0;
    		}
    		else if(sum == 2)
    		{
    			s[i+1] = '0';
    			adv = 1;
    		}
    	}
    	if(adv == 1) s[0] = '1';
    	else s = s.substr(1);
    	return s;
    }
};    