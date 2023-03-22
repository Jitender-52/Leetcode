class Solution {
public:
    
    int dfs(int src, vector<int> &vis, vector<vector<int>> &adj, map<pair<int,int>,int> &mp)
    {
        vis[src] = 1;
        int ans = INT_MAX;
        for(auto i : adj[src])
        {
            ans = min(ans, mp[{src, i}]);
            ans = min(ans, mp[{i, src}]);
            if(!vis[i])
            {
                ans = min(ans, dfs(i, vis, adj, mp));
            }
        }
        return ans;
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        
        map<pair<int,int>,int> mp;
        for(int i = 0; i < m; i++)
        {
            mp[{roads[i][0], roads[i][1]}] = roads[i][2];
            mp[{roads[i][1], roads[i][0]}] = roads[i][2];
        }

        vector<vector<int>> adj(n+1);
        for(int i = 0; i < m; i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        vector<int> vis(n+1, 0);
        return dfs(1, vis, adj, mp);
    }
};