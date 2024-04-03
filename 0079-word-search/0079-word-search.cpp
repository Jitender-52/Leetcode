class Solution {
public:
    
    vector<vector<int>> vis;
    int n, m, l;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    bool solve(int i, int j, int k, vector<vector<char>> &board, string &word)
    {
        if(k == l)
            return true;
        if(i < 0 || i >= n || j < 0 || j >= m || vis[i][j] || board[i][j] != word[k])
            return false;
        vis[i][j] = 1;
        for(int x = 0; x < 4; x++)
        {
            if(solve(i + dx[x], j + dy[x], k+1, board, word))
                return true;
        }
        vis[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        l = word.size();
        vis.resize(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(solve(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};