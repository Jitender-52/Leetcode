class Solution {
public:
    
    
        void cycle(int src, vector<int> &vis, vector<int> &dfs, vector<vector<int>> &adj, int count, int &ans)
    {
        vis[src] = 1;
        dfs[src] = count;
        
        for(auto i : adj[src])
        {
            if(vis[i] && dfs[i] != -1)
            {
                ans = max(ans, dfs[src] - dfs[i] + 1);
                return;
            }
            else if(!vis[i])
            {
                cycle(i, vis, dfs, adj, count+1, ans);
            }
        }
        dfs[src] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n; i++)
        {
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }
        
        vector<int> dfs(n+1, -1);
        vector<int> vis(n+1, 0);
        
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                cycle(i, vis, dfs, adj, 0, ans);
            }
        }
        return ans;
    }
};
    
    
    
    // Giving TLE
    
//     void cycle(int src, vector<int> &edges, vector<int> &dist, vector<int> &vis, int &ans)
//     {
//         int i = edges[src];
//         vis[src] = 1;
//         if(i != -1 && !vis[i])
//         {
//             dist[i] = dist[src]+1;
//             cycle(i, edges, dist, vis, ans);
//         }
//         else if(i != -1 && dist[i] > 0)
//         {
//             ans = max(ans, dist[src] - dist[i] + 1);
//         }
//     }
    
//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
        
//         vector<int> vis(n+1, 0);
        
//         int ans = -1;
//         for(int i = 0; i < n; i++)
//         {
//             if(!vis[i])
//             {
//                 vector<int> dist(n+1, -1);
//                 dist[i] = 1;
//                 cycle(i, edges, dist, vis, ans);
//             }
//         }
//         return ans;
//     }
// };
    
    
    
//     Runtime: 418 ms, faster than 48.12% of C++ online submissions for Longest Cycle in a Graph.
// Memory Usage: 184.3 MB, less than 28.85% of C++ online submissions for Longest Cycle in a Graph.
    
    
    // without passing & before dfs vector it will give TLE
    
//         void cycle(int src, vector<int> &vis, vector<int> &dfs, vector<vector<int>> &adj, int count, int &ans)
//     {
//         vis[src] = 1;
//         dfs[src] = count;
        
//         for(auto i : adj[src])
//         {
//             if(vis[i] && dfs[i] != -1)
//             {
//                 ans = max(ans, dfs[src] - dfs[i] + 1);
//                 return;
//             }
//             else if(!vis[i])
//             {
//                 cycle(i, vis, dfs, adj, count+1, ans);
//             }
//         }
//         dfs[src] = -1; // Without passing &(address) it will give TLE
//     }
    
//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
//         vector<vector<int>> adj(n+1);
//         for(int i = 0; i < n; i++)
//         {
//             if(edges[i] != -1)
//                 adj[i].push_back(edges[i]);
//         }
        
//         vector<int> dfs(n+1, -1);
//         vector<int> vis(n+1, 0);
        
//         int ans = -1;
//         for(int i = 0; i < n; i++)
//         {
//             if(!vis[i])
//             {
//                 cycle(i, vis, dfs, adj, 0, ans);
//             }
//         }
//         return ans;
//     }
// };
    
    
    
//     Runtime: 390 ms, faster than 52.39% of C++ online submissions for Longest Cycle in a Graph.
// Memory Usage: 184.2 MB, less than 28.97% of C++ online submissions for Longest Cycle in a Graph.

    
//     void cycle(int src, vector<int> &vis, vector<int> &dfs, vector<vector<int>> &adj, int count, int &ans)
//     {
//         vis[src] = 1;
//         dfs[src] = count;
        
//         for(auto i : adj[src])
//         {
//             if(vis[i] && dfs[i] != -1)
//             {
//                 ans = max(ans, dfs[src] - dfs[i] + 1);
//                 return;
//             }
//             else if(!vis[i])
//             {
//                 cycle(i, vis, dfs, adj, count+1, ans);
//             }
//         }
//         dfs[src] = -1;
//     }
    
//     int longestCycle(vector<int>& edges) {
//         int n = edges.size();
//         vector<vector<int>> adj(n+1);
//         for(int i = 0; i < n; i++)
//         {
//             if(edges[i] != -1)
//                 adj[i].push_back(edges[i]);
//         }
        
//         vector<int> dfs(n+1, -1);
//         vector<int> vis(n+1, 0);
        
//         int ans = -1;
//         for(int i = 0; i < n; i++)
//         {
//             if(!vis[i])
//             {
//                 cycle(i, vis, dfs, adj, 0, ans);
//             }
//         }
//         return ans;
//     }
// };