class Solution {
public:
    
//     Runtime: 28 ms, faster than 49.66% of C++ online submissions for Number of Provinces.
// Memory Usage: 13.8 MB, less than 72.35% of C++ online submissions for Number of Provinces.

    
    void dfs(int src, vector<vector<int>> &adj, vector<int> &vis)
    {
        int n = adj.size();
        vis[src] = 1;
        // for(auto i : adj[src])
        for(int i = 1; i <= n; i++)
        {
            // cout << src <<" " << i << " " << vis[i] << " " << adj[src][i-1] << endl;
            if(!vis[i] && adj[src-1][i-1] == 1)
            {
                dfs(i, adj, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1, 0);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};