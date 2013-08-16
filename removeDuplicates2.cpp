class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n < 1) return 0;
        int pre = A[0],cnt = 1;
        vector<int> B(1,pre);
        for(int i = 1;i < n;i++)
        {
        	if(A[i] == pre)
        	{
        		if(cnt == 2)
        			continue;
        		else
    			{
    				B.push_back(A[i]);
    				cnt++;
    			}
        	}
        	else
        	{
        		pre = A[i];
        		cnt = 1;
        		B.push_back(A[i]);
        	}
        }
        for(int i = 0;i < B.size();i++)
        {
        	A[i] = B[i];
        }
        return B.size();
    }
};