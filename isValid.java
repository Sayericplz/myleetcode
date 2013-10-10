public class Solution {
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Character> stack = new Stack<Character>();
        for(int i = 0;i < s.length();i++)
        {
        	char c = s.charAt(i);
        	switch(c)
        	{
        		case '(':
        		case '{':
        		case '[':
        			stack.push(c);
        			break;
        		case ')':
        		{
        			if(stack.empty() || stack.pop() != '(')
        				return false;
        			break;
        		}
        		case '}':
        		{
        			if(stack.empty() || stack.pop() != '{')
        				return false;
        			break;
        		}
        		case ']':
        		{
        			if(stack.empty() || stack.pop() != '[')
        				return false;
        			break;
        		}
        	}
        }
        if(stack.empty()) return true;
        return false;
    }
}