class Solution {
public:
    
    bool isCycle(int src, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
    {
        vis[src] = true;
        dfs[src] = true;
        for(auto i : adj[src])
        {
            if(vis[i] && dfs[i])
                return true;
            else if(!vis[i])
                if(isCycle(i, vis, adj, dfs))
                    return true;
        }
        dfs[src] = false;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> adj[n];
        for(int i = 0; i < m; i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(n);
        vector<int> dfs(n);
        for(int i = 0 ;i < n; i++)
        { 
            if(isCycle(i, vis, adj, dfs))
                return false;
        }
        return true;
    }
};