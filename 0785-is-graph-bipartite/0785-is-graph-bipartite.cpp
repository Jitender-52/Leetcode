class Solution {
public:
    
    bool isBipartiteBFS(int src, vector<vector<int>> &adj, vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            for (auto child : adj[parent])
            {
                if (color[child] == color[parent])
                    return false;
                if (color[child] == -1)
                {
                    color[child] = color[parent] ^ 1;
                    q.push(child);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>> &adj){
        int n = adj.size();
        vector<int> color(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (!isBipartiteBFS(i, adj, color))
                {
                    return 0;
                }
            }
        }
        return 1;
    }
};

    
    
//     Runtime: 102 ms, faster than 5.06% of C++ online submissions for Is Graph Bipartite?.
// Memory Usage: 57.4 MB, less than 5.01% of C++ online submissions for Is Graph Bipartite?.
    
//     bool bipartiteDfs(int node, vector<vector<int>> adj, int color[])
//     {
//         if (color[node] == -1)
//         {
//             color[node] = 1;
//         }

//         for (auto i : adj[node])
//         {
//             if (color[i] == -1)
//             {
//                 color[i] = 1 - color[node];
//                 if (!bipartiteDfs(i, adj, color))
//                 {
//                     return false;
//                 }
//             }
//             else if (color[node] == color[i]) // If we will use this condition first then it will take less time to run due to less number of recursive calls
//             {
//                 return false;
//             }
//         }
//         return true;
//     }

//     bool isBipartite(vector<vector<int>> &adj)
//     {
//         int n = adj.size();
//         int color[n];
//         for (int i = 0; i < n; i++)
//         {
//             color[i] = -1;
//         }

//         for (int i = 0; i < n; i++)
//         {
//             if (!bipartiteDfs(i, adj, color))
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// };