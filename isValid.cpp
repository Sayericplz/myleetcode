class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     	vector<char> stack;
     	for(int i = 0;i < s.size();i ++)
     	{
     		switch(s[i])
     		{
     			case '(':stack.push_back(s[i]);break;
     			case ')':
				{
					if(stack.size()==0 || stack.back()!='(')
					{
						return false;
					}
					else
					{
						stack.pop_back();
					}
					break;
				}
				case '{':stack.push_back(s[i]);break;
     			case '}':
				{
					if(stack.size()==0 || stack.back()!='{')
					{
						return false;
					}
					else
					{
						stack.pop_back();
					}
					break;
				}
				case '[':stack.push_back(s[i]);break;
     			case ']':
				{
					if(stack.size()==0 || stack.back()!='[')
					{
						return false;
					}
					else
					{
						stack.pop_back();
					}
					break;
				}
     		}
     	}
     	if(stack.size()==0)
     	{
     		return true;
     	}
     	return false;
    }
};