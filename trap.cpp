struct Point{
	int h;
	int pos;	
};

class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,sum=0;
        vector<Point> ps; 
        for(i = 0;i < n;i++)
        {
        	int h = 0;
        	if(A[i] > 0)
        	{
        		while(ps.size() > 0 && ps.back().h <= A[i])
        		{
        			sum += (ps.back().h - h) * (i - ps.back().pos - 1);
        			h = ps.back().h;
        			ps.pop_back();
        		}
        		if(ps.size() > 0)
        		{
        			sum += (A[i] - h) * (i - ps.back().pos - 1);
        		}
        		struct Point s;
        		s.h = A[i];
        		s.pos = i;
        		ps.push_back(s);
        	}
        }
        return sum;
    }
};