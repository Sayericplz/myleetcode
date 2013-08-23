class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0,j = s.size()-1;
        while(i < j)
        {
        	while(i<s.size()&&!((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')))
        		i++;
        	if(i==s.size()) break;
        	while(j>=0&&!((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')))
        		j--;
        	if(j<0) break;
        	if(s[i]>='0'&&s[i]<='9'&&s[i]!=s[j])
        		return false;
        	if(s[i]>='a'&&s[i]<='z'&&(s[i]!=s[j]&&s[i]-s[j]!=32))
        		return false;
        	if(s[i]>='A'&&s[i]<='Z'&&(s[i]!=s[j]&&s[j]-s[i]!=32))
        		return false;
        	i++;
        	j--;
        }
        return true;
    }
};