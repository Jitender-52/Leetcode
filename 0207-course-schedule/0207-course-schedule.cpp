class Solution {
public:
    
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n);
        for(auto i : prerequisites)
        {
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        
        int count = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto i : adj[node])
            {
                indegree[i]--;
                if(!indegree[i])
                    q.push(i);
            }
            count++;
        }
        return count == n;
    }
};
    
    
    
//     Runtime: 25 ms, faster than 60.97% of C++ online submissions for Course Schedule.
// Memory Usage: 13.2 MB, less than 84.80% of C++ online submissions for Course Schedule.
    
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         vector<int> indegree(n+1);
//         int m = prerequisites.size();
        
//         vector<vector<int>> adj(n);
//         for(int i = 0; i < m; i++)
//         {
//             indegree[prerequisites[i][0]]++;
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }
        
//         queue<int> q;
//         for(int i = 0; i < n; i++)
//         {
//             if(!indegree[i])
//                 q.push(i);
//         }
        

        
//         int count = 0;
//         while(!q.empty())
//         {
//             int node = q.front();
//             q.pop();
//             for(auto i : adj[node])
//             {
//                 indegree[i]--;
//                 if(indegree[i] == 0)
//                     q.push(i);
//             }
//             count++;
//         }
//         // cout << count << endl;
//         return (count == n);
//     }
// };
    
    
//     Runtime: 17 ms, faster than 94.40% of C++ online submissions for Course Schedule.
// Memory Usage: 13.6 MB, less than 71.26% of C++ online submissions for Course Schedule.
    
    
//     bool isCycle(int src, vector<int> &vis, vector<int> adj[], vector<int> &dfs)
//     {
//         vis[src] = true;
//         dfs[src] = true;
//         for(auto i : adj[src])
//         {
//             if(vis[i] && dfs[i])
//                 return true;
//             else if(!vis[i])
//                 if(isCycle(i, vis, adj, dfs))
//                     return true;
//         }
//         dfs[src] = false;
//         return false;
//     }
    
//     bool canFinish(int n, vector<vector<int>>& prerequisites) {
//         int m = prerequisites.size();
//         vector<int> adj[n];
//         for(int i = 0; i < m; i++)
//         {
//             int u = prerequisites[i][0];
//             int v = prerequisites[i][1];
//             adj[u].push_back(v);
//         }
        
//         vector<int> vis(n);
//         vector<int> dfs(n);
//         for(int i = 0 ;i < n; i++)
//         { 
//             if(isCycle(i, vis, adj, dfs))
//                 return false;
//         }
//         return true;
//     }
// };