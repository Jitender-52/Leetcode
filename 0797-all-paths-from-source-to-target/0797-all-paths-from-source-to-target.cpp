class Solution {
public:
    
    // BFS
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            for(auto j : graph[i])
            {
                adj[i].push_back(j);
            }
        }
        
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty())
        {
            auto path = q.front();
            q.pop();
            if(path.back() == n-1)
            {
                ans.push_back(path);
            }
            else
            {
                for(auto i : adj[path.back()])
                {
                    path.push_back(i);
                    q.push(path);
                    path.pop_back();
                }
            }
        }
        return ans;
    }
};
    
    
    // DFS
    
//     Runtime: 11 ms, faster than 87.32% of C++ online submissions for All Paths From Source to Target.
// Memory Usage: 10.6 MB, less than 64.13% of C++ online submissions for All Paths From Source to Target.
    
//     void dfs(int src, vector<vector<int>> &adj, vector<int> &v, vector<vector<int>> &ans)
//     {
//         int n = adj.size();
//         v.push_back(src);
//         if(src == n-1)
//         {
//             ans.push_back(v);
//             v.pop_back();
//             return;
//         }
//         for(auto i : adj[src])
//         {
//             dfs(i, adj, v, ans);
//         }
//         v.pop_back();
//     }
    
//     vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<vector<int>> adj(n);
//         for(int i = 0; i < n; i++)
//         {
//             for(auto j : graph[i])
//                 adj[i].push_back(j);
//         }
        
//         vector<vector<int>> ans;
//         vector<int> v;
//         dfs(0, adj, v, ans);
//         return ans;
//     }
// };