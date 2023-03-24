class Solution {
public:
    
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<pair<int,int>>> adj(n);
            for(auto i : connections)
            {
                adj[i[0]].push_back({i[1], 1});
                adj[i[1]].push_back({i[0], 0});
            }
            
            queue<int> q;
            q.push(0);
            vector<int> vis(n, 0);
            vis[0] = 1;
            
            int ans = 0;
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                for(auto i : adj[temp])
                {
                    if(!vis[i.first])
                    {
                        vis[i.first] = 1;
                        q.push(i.first);
                        ans += i.second;
                    }
                }
            }
            return ans;
        }
};
    
    
    
//     Runtime: 645 ms, faster than 22.90% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
// Memory Usage: 145.3 MB, less than 21.27% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
    
    
//     int dfs(int src, vector<vector<int>> &adj, map<pair<int,int>,int> &mp, vector<int> &vis)
//     {
//         // cout << src << endl;
//         vis[src] = 1;
//         int ans = 0;
//         for(auto i : adj[src])
//         {
//             if(!vis[i])
//             {
//                 // cout << i << " " << src << " " << mp[{i,src}] << endl;
//                 ans += mp[{i, src}];
//                 ans += dfs(i, adj, mp, vis);
//             }
//         }
//         // cout << ans << endl;
//         return ans;
//     }
    
//     int minReorder(int n, vector<vector<int>>& connections) {
//         int m = connections.size();
        
//         // vector<vector<pair<int,int>>> adj(n);
//         // vector<map<int,int>> mp;
//         vector<vector<int>> adj(n);
//         map<pair<int,int>, int> mp;
//         for(int i = 0; i < m; i++)
//         {
//             int a = connections[i][0];
//             int b = connections[i][1];
            
//             // adj[a][b] += 1;
//             // adj[b][a] += 0;
            
//             adj[a].push_back(b);
//             adj[b].push_back(a);
            
//             mp[{a,b}] += 0;
//             mp[{b,a}] += 1;
            
//             // auto mp = adj[a];
//             // mp[b] += 1;
//             // adj[a] = mp;
//             // mp = adj[b];
//             // mp[b] += 0;
//             // adj[b] = mp;
//         }
        
//         // for(auto i : mp)
//         // {
//         //     cout << (i.first).first << "," << (i.first).second << "->" << i.second << endl;
//         // }
    
//         vector<int> vis(n, 0);
//         return dfs(0, adj, mp, vis);
//     }
// };