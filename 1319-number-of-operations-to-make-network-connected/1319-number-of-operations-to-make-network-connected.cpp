class Solution {
public:
    
    void dfs(int src, vector<int> &vis, int &count, vector<vector<int>> &adj)
    {
        vis[src] = 1;
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                dfs(i, vis, count, adj);
            }
            // else if(i != src)
            // {
            //     cout << src << " " << i << endl;
            //     count++;
            // }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        if(m < n-1)
            return -1;
        
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < m; i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int count = 0;
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, vis, count, adj);
            }
        }
        ans--;
        return ans;
        
        // cout << count << " " << ans << endl;
        // if(ans > count)
        // {
        //     return -1;
        // }
        // return count - ans;
    }
};