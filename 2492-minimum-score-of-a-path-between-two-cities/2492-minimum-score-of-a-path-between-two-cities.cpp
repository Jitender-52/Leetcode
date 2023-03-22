class Solution {
public:
    
    
    
    int minScore(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        
        map<pair<int,int>,int> mp;
        for(int i = 0; i < m; i++)
        {
            mp[{roads[i][0], roads[i][1]}] = roads[i][2];
            mp[{roads[i][1], roads[i][0]}] = roads[i][2];
        }

        vector<vector<int>> adj(n+1);
        for(int i = 0; i < m; i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        // vector<int> vis(n+1, 0);
        // return dfs(1, vis, adj, mp);
        
        int ans = INT_MAX;
        queue<int> q;
        vector<int> vis(n+1, 0);
        q.push(1);
        vis[1] = 1;
        
        while(!q.empty())
        {
            int src = q.front();
            q.pop();
            
            for(auto i : adj[src])
            {
                ans = min({ans, mp[{src, i}], mp[{i, src}]});
                if(!vis[i])
                {
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return ans;
    }
};
    
    
//     Runtime: 972 ms, faster than 5.70% of C++ online submissions for Minimum Score of a Path Between Two Cities.
// Memory Usage: 167.1 MB, less than 10.62% of C++ online submissions for Minimum Score of a Path Between Two Cities.
    
//     int dfs(int src, vector<int> &vis, vector<vector<int>> &adj, map<pair<int,int>,int> &mp)
//     {
//         vis[src] = 1;
//         int ans = INT_MAX;
//         for(auto i : adj[src])
//         {
//             ans = min(ans, mp[{src, i}]);
//             ans = min(ans, mp[{i, src}]);
//             if(!vis[i])
//             {
//                 ans = min(ans, dfs(i, vis, adj, mp));
//             }
//         }
//         return ans;
//     }
    
//     int minScore(int n, vector<vector<int>>& roads) {
//         int m = roads.size();
        
//         map<pair<int,int>,int> mp;
//         for(int i = 0; i < m; i++)
//         {
//             mp[{roads[i][0], roads[i][1]}] = roads[i][2];
//             mp[{roads[i][1], roads[i][0]}] = roads[i][2];
//         }

//         vector<vector<int>> adj(n+1);
//         for(int i = 0; i < m; i++)
//         {
//             adj[roads[i][0]].push_back(roads[i][1]);
//             adj[roads[i][1]].push_back(roads[i][0]);
//         }
        
//         vector<int> vis(n+1, 0);
//         return dfs(1, vis, adj, mp);
//     }
// };