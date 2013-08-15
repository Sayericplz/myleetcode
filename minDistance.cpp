class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = word1.size(),len2 = word2.size();
        vector<vector<int> > dis(len1+1,vector<int>(len2+1,0));
        for(int i = 0;i <= len1;i++) dis[i][0] = i;
        for(int i = 0;i <= len2;i++) dis[0][i] = i;
        for(int i = 1;i <= len1;i++)
        {
        	for(int j = 1;j <= len2;j++)
        	{
        		if(word1[i-1] == word2[j-1])
        			dis[i][j] = dis[i-1][j-1];
        		else
        			dis[i][j] = dis[i-1][j-1]+1;
        		int tmp = (dis[i-1][j] < dis[i][j-1]?dis[i-1][j]:dis[i][j-1])+1;
        		dis[i][j] = tmp<dis[i][j]?tmp:dis[i][j];
        	}
        }
        return dis[len1][len2];
    }
};