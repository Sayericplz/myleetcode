class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = num1.size(),len2 = num2.size(),i,j;
        int len3 = len1 + len2;
        if(len1 == 0 || len2 == 0) return "";
        if((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) return "0";
        int *res = new int[len3];
        for(i = 0;i < len3;i++) res[i] = 0;
        for(i = 0;i < len1;i++)
        {
        	for(j = 0;j < len2;j++)
        	{
        		res[len3-i-j-2] += (num1[i] - 48) * (num2[j] - 48);
        	}
        }
        for(i = 0;i < len3;i++)
        {
        	if(res[i] > 9)
        	{
        		res[i+1] += res[i]/10;
        		res[i] = res[i] % 10;
        	}
        }
        string s = "";
        i = len3-1;
        while(res[i] == 0)
        {
        	i--;
        }
        for(j = i;j >= 0; j--)
        {
        	char ch = res[j] +'0';
        	s += ch;
        }
        delete []res;
        return s;
    }
};