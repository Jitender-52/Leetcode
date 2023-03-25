class Solution {
public:
    
    long long dfs(int src, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[src] = 1;
        long long ans = 0;
        for(auto i : adj[src])
        {
            if(!vis[i])
                ans += dfs(i, vis, adj);
        }
        return ans + 1;
    }
        
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        long long ans = 0;
        long long count = 0;
        vector<int> vis(n+1, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                long long x = dfs(i, vis, adj);
                ans += x * (n - x - count);
                count += x;
            }
        }
        return ans;
    }
};