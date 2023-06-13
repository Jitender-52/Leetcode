class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O')
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        auto isValid = [&](int i, int j)
        {
            return (i >= 0 && i < n && j >= 0 && j < m);  
        };
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(isValid(nx, ny) && board[nx][ny] == 'O' && !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(board[i][j] == 'O' && !vis[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};