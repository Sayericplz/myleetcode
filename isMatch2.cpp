class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(*s == 0)
        {
            while(*p != 0 && *p == '*')
                p++;
            return *p == 0;
        }
        if(*p == 0) return false;
        const char *flag_s = NULL,*flag_p = NULL;
        while(*s)
        {
            if(*s == *p || *p == '?')
            {
                s++;
                p++;
            }
            else if(*p == '*')
            {
                while(*p == '*') p++;
                if(*p == 0) return true;
                flag_s = s;
                flag_p = p;
            }
            else if(flag_p && (!*p || *s != *p))
            {
                s = ++flag_s;
                p = flag_p;
            }
            else
            {
                return false;
            }
        }
        while(*p == '*') p++;
        if(*p != 0) return false;
        return true;
    }
};