class Solution {
public:
    
    void dfs(int src, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[src] = 1;
        for(auto i : adj[src])
        {
            if(!vis[i])
            {
                dfs(i, vis, adj);
            }
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
        
        int ans = 0;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(i, vis, adj);
            }
        }
        return ans-1;
    }
};
    
//     Runtime: 136 ms, faster than 65.83% of C++ online submissions for Number of Operations to Make Network Connected.
// Memory Usage: 52 MB, less than 34.51% of C++ online submissions for Number of Operations to Make Network Connected.
    
//     void dfs(int src, vector<int> &vis, int &count, vector<vector<int>> &adj)
//     {
//         vis[src] = 1;
//         for(auto i : adj[src])
//         {
//             if(!vis[i])
//             {
//                 dfs(i, vis, count, adj);
//             }
//             // else if(i != src)
//             // {
//             //     cout << src << " " << i << endl;
//             //     count++;
//             // }
//         }
//     }
    
//     int makeConnected(int n, vector<vector<int>>& connections) {
//         int m = connections.size();
        
//         if(m < n-1)
//             return -1;
        
//         vector<vector<int>> adj(n+1);
//         for(int i = 0; i < m; i++)
//         {
//             adj[connections[i][0]].push_back(connections[i][1]);
//             adj[connections[i][1]].push_back(connections[i][0]);
//         }
        
//         int count = 0;
//         int ans = 0;
//         vector<int> vis(n, 0);
//         for(int i = 0; i < n; i++)
//         {
//             if(!vis[i])
//             {
//                 ans++;
//                 dfs(i, vis, count, adj);
//             }
//         }
//         ans--;
//         return ans;
        
//         // cout << count << " " << ans << endl;
//         // if(ans > count)
//         // {
//         //     return -1;
//         // }
//         // return count - ans;
//     }
// };