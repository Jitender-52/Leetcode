class Solution {
public:

    // BFS
    
        long long bfs(int src, vector<int> &vis, vector<vector<int>> &adj)
        {
            queue<int> q;
            q.push(src);
            vis[src] = 1;
            long long ans = 0;
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                for(auto i : adj[temp])
                {
                    if(!vis[i])
                    {
                        ans += bfs(i, vis, adj);
                        vis[i] = 1;
                    }
                }
            }
            return ans + 1; // +1 For counting the source element;
        }
    
        long long countPairs(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for(auto i : edges)
            {
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }
            vector<int> vis(n,0);
            
            // auto dfs = [&](int src)
            // {
            //     vis[src] = 1;
            //     long long ans = 1;
            //     for(auto i : adj[src])
            //     {
            //         if(!vis[i])
            //         {
            //             // ans += dfs(i);
            //         }
            //     }
            //     return ans;
            // };
            
            // auto bfs = [&](int src)
            // {
            //     queue<int> q;
            //     q.push(src);
            //     vis[src] = 1;
            //     long long ans = 0;
            //     while(!q.empty())
            //     {
            //         int temp = q.front();
            //         for(auto i : adj[temp])
            //         {
            //             if(!vis[i])
            //             {
            //                 vis[i] = 1;
            //                 q.push(i);
            //                 ans++;
            //             }
            //         }
            //     }
            //     return ans;
            // };
            
            long long ans = 0;
            long long count = 0;
            for(int i = 0; i < n; i++)
            {
                if(!vis[i])
                {
                    // long long x = (long long)dfs(i);
                    long long x = bfs(i, vis, adj);
                    ans += x * (n - x - count);
                    count += x;
                }
            }
            return ans;
        }
};
    
    
    
//     Runtime: 641 ms, faster than 61.59% of C++ online submissions for Count Unreachable Pairs of Nodes in an Undirected Graph.
// Memory Usage: 205.5 MB, less than 34.45% of C++ online submissions for Count Unreachable Pairs of Nodes in an Undirected Graph.

    // DFS
    
//     long long dfs(int src, vector<int> &vis, vector<vector<int>> &adj)
//     {
//         vis[src] = 1;
//         long long ans = 0;
//         for(auto i : adj[src])
//         {
//             if(!vis[i])
//                 ans += dfs(i, vis, adj);
//         }
//         return ans + 1;
//     }
        
//     long long countPairs(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for(auto v : edges)
//         {
//             adj[v[0]].push_back(v[1]);
//             adj[v[1]].push_back(v[0]);
//         }
        
//         long long ans = 0;
//         long long count = 0;
//         vector<int> vis(n+1, 0);
//         for(int i = 0; i < n; i++)
//         {
//             if(!vis[i])
//             {
//                 long long x = dfs(i, vis, adj);
//                 ans += x * (n - x - count);
//                 count += x;
//             }
//         }
//         return ans;
//     }
// };