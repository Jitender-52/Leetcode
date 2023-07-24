class Solution {
public:
    
    int dfs(int src, vector<vector<int>> &adj, vector<int> &quiet, vector<int> &v)
    {
        if(v[src] != -1)
            return v[src];
        
        v[src] = src;
        for(auto i : adj[src])
        {
            int a = dfs(i, adj, quiet, v);
            if(quiet[a] < quiet[v[src]])
                v[src] = a;
        }
        return v[src];
    }
    
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto i : richer)
        {
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> v(n, -1);
        for(int i = 0; i < n; i++)
        {
            dfs(i, adj, quiet, v);
        }
        return v;
    }
};
    
    
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         int n = quiet.size();
//         vector<vector<int>> adj(n);
//         for(auto i : richer)
//         {
//             adj[i[1]].push_back(i[0]);
//         }
        
//         vector<int> ans;
//         auto bfs = [&](int src)
//         {
//             queue<int> q;
//             vector<int> v;
//             q.push(src);
//             while(!q.empty())
//             {
//                 // v.clear();
//                 int sz = q.size();
//                 for(int i = 0; i < sz; i++)
//                 {
//                     auto node = q.front();
//                     v.push_back(node);
//                     q.pop();
//                     for(auto it : adj[node])
//                     {
//                         q.push(it);
//                     }
//                 }
//             }
//             int mini = INT_MAX;
//             for(int i = 0; i < v.size(); i++)
//             {
//                 mini = min(mini, quiet[v[i]]);
//             }
//             for(auto i : v)
//             {
//                 if(quiet[i] == mini)
//                     return i;
//             }
//             return quiet[src];
//         };
        
//         for(int i = 0; i < n; i++)
//         {
//             ans.push_back(bfs(i));
//         }
//         return ans;
//     }
// };