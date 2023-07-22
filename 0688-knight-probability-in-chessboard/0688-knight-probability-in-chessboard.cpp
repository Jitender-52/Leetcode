class Solution {
public:
    
    vector<vector<int>> dr = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    
    bool isValid(int r, int c, int n)
    {
        return (r >= 0 && r < n && c >= 0 && c < n);
    }
    
    double find(int r, int c, int n, int k, vector<vector<vector<double>>> &dp)
    {
        
        if(!isValid(r, c, n))
            return 0;
        
        if(k == 0)
            return 1;
        
        if(dp[r][c][k] != -1)
            return dp[r][c][k];
        
        double p = 0;
        for(int i = 0; i < 8; i++)
        {
            p += find(r + dr[i][0], c + dr[i][1], n, k-1, dp) / 8;
        }
        
        return dp[r][c][k] = p;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>> (n+1, vector<double> (k+1, -1)));
        return find(row, column, n, k, dp);
    }
};