class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = word.size();
        if(!len) return true;
        int m = board.size();
        if(!m) return false;
        int n = board[0].size();
        if(!n) return false;
        vector<vector<bool> > flag(m,vector<bool>(n,true));
        vector<int> start;
        for(int i = 0;i < m;i++)
        {
        	for(int j = 0;j < n;j++)
        	{
        		if(board[i][j] == word[0])
        			start.push_back(i*n+j);
        	}
        }
        for(int i = 0;i < start.size();i++)
        {
        	int pos = start[i];
        	flag[pos/n][pos%n] = false;
        	if(dfs(pos,word,1,flag,board)) return true;
        	flag[pos/n][pos%n] = true;
        }
        return false;
    }

    bool dfs(int pos,string &word,int step,vector<vector<bool> > &flag,vector<vector<char> > &board)
    {
    	if(step == word.size())
    		return true;
    	int m = board.size();
    	int n = board[0].size();
    	if(pos-n >= 0 && flag[pos/n-1][pos%n] && board[pos/n-1][pos%n] == word[step])
    	{
    		flag[pos/n-1][pos%n] = false;
    		if(dfs(pos-n,word,step+1,flag,board)) return true;
    		flag[pos/n-1][pos%n] = true;
    	}
    	if(pos+n < m*n && flag[pos/n+1][pos%n] && board[pos/n+1][pos%n] == word[step])
    	{
    		flag[pos/n+1][pos%n] = false;
    		if(dfs(pos+n,word,step+1,flag,board)) return true;
    		flag[pos/n+1][pos%n] = true;
    	}
    	if(pos%n-1 >= 0 && flag[(pos-1)/n][(pos-1)%n] && board[(pos-1)/n][(pos-1)%n] == word[step])
    	{
    		flag[(pos-1)/n][(pos-1)%n] = false;
    		if(dfs(pos-1,word,step+1,flag,board)) return true;
    		flag[(pos-1)/n][(pos-1)%n] = true;
    	}
    	if(pos%n+1 < n && flag[(pos+1)/n][(pos+1)%n] && board[(pos+1)/n][(pos+1)%n] == word[step])
    	{
    		flag[(pos+1)/n][(pos+1)%n] = false;
    		if(dfs(pos+1,word,step+1,flag,board)) return true;
    		flag[(pos+1)/n][(pos+1)%n] = true;
    	}
    	return false;
    }
};