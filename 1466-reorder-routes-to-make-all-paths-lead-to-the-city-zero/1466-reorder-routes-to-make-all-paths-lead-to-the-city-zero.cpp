class Solution {
public:
    
    int dfs(int src, vector<vector<int>> &adj, map<pair<int,int>,int> &mp, vector<int> &vis)
    {
        // cout << src << endl;
        vis[src] = 1;
        int ans = 0;
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                // cout << i << " " << src << " " << mp[{i,src}] << endl;
                ans += mp[{i, src}];
                ans += dfs(i, adj, mp, vis);
            }
        }
        // cout << ans << endl;
        return ans;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        // vector<vector<pair<int,int>>> adj(n);
        // vector<map<int,int>> mp;
        vector<vector<int>> adj(n);
        map<pair<int,int>, int> mp;
        for(int i = 0; i < m; i++)
        {
            int a = connections[i][0];
            int b = connections[i][1];
            
            // adj[a][b] += 1;
            // adj[b][a] += 0;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
            
            mp[{a,b}] += 0;
            mp[{b,a}] += 1;
            
            // auto mp = adj[a];
            // mp[b] += 1;
            // adj[a] = mp;
            // mp = adj[b];
            // mp[b] += 0;
            // adj[b] = mp;
        }
        
        // for(auto i : mp)
        // {
        //     cout << (i.first).first << "," << (i.first).second << "->" << i.second << endl;
        // }
    
        vector<int> vis(n, 0);
        return dfs(0, adj, mp, vis);
    }
};