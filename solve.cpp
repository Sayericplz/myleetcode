class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if(m < 3) return;
        int n = board[0].size();
        if(n < 3) return;
        vector<vector<bool> > f(m,vector<bool>(n,true));
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int i = 0;i < m;i++)
        {
        	for(int j = 0;j < n;j++)
        	{
        		vector<int> qx;
        		vector<int> qy;
        		if(f[i][j]&&board[i][j]=='O')
        		{
        			qx.push_back(i);
        			qy.push_back(j);
        			f[i][j] = false;
        			bool e = i==0||i==m-1||j==0||j==n-1;
        			int cnt = 0;
        			while(cnt < qx.size())
        			{
        				int x = qx[cnt];
        				int y = qy[cnt];
        				cnt++;
        				for(int k = 0;k < 4;k++)
        				{
        					int nx = x+dx[k];
        					int ny = y+dy[k];
        					if(nx>=0&&nx<m&&ny>=0&&ny<n&&f[nx][ny]&&board[nx][ny]=='O')
        					{
        						f[nx][ny] = false;
        						qx.push_back(nx);
        						qy.push_back(ny);
        						if(nx==0||nx==m-1||ny==0||ny==n-1) e = true;
        					}
        				}
        			}
        			if(!e)
        			{
        				for(int k = 0;k < qx.size();k++)
        				{
        					board[qx[k]][qy[k]] = 'X';
        				}
        			}
        		}
        	}
        }
    }
};