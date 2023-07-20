class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n == 1)
            return {0};
        
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0), ans;
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(degree[i] == 1)
                q.push(i);
        }
        
        while(!q.empty())
        {
            ans.clear();
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto child : adj[node])
                {
                    degree[child]--;
                    if(degree[child] == 1)
                        q.push(child);
                }
            }
        }
        return ans;
    }
};
    
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         for(auto i : edges)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
        
//         vector<pair<int,int>> v; // {maxDist, node}}
//         // vector<int> vis(n, 0);
//         auto bfs = [&](int src)
//         {
//             vector<int> vis(n, 0);
//             queue<int> q;
//             q.push(src);
//             vis[src] = 1;
//             int height = 0;
//             while(!q.empty())
//             {
//                 int sz = q.size();
//                 for(int i = 0; i < sz; i++)
//                 {
//                     auto node = q.front();
//                     q.pop();
//                     for(auto nnode : adj[node])
//                     {
//                         if(!vis[nnode])
//                         {
//                             vis[nnode] = 1;
//                             q.push(nnode);
//                         }
//                     }
//                 }
//                 height++;
//             }
//             return height;
//         };
        
//         for(int i = 0; i < n; i++)
//         {
//             v.push_back({bfs(i), i});
//         }
//         sort(v.begin(), v.end());
        
//         int i = 0;
//         vector<int> ans;
//         while(i < n && v[i].first == v[0].first)
//         {
//             ans.push_back(v[i].second);
//             i++;
//         }
//         return ans;
//     }
// };