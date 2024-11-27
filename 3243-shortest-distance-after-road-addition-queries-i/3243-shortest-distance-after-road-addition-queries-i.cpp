class Solution {
public:
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n+1);
        for(int i = 0; i < n-1; i++)
        {
            adj[i].push_back(i+1);
        }
        
        vector<int> ans;
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        for(auto x : queries)
        {
            adj[x[0]].push_back(x[1]);
            if(x[1] > x[0] && dist[x[1]] > dist[x[0]] + 1)   // Do not need first condition(i.e x[1] > x[0]) may fail due to this condition, may be any testcase can be added in future. So if fails can remove it. It is added to reduce complexity for weak testcases.
            {
                dist[x[1]] = dist[x[0]] + 1;
                q.push(x[1]);
            }
            while(!q.empty())
            {
                int sz = q.size();
                for(int i = 0; i < sz; i++)
                {
                    auto it = q.front();
                    q.pop();
                    for(auto j : adj[it])
                    {
                        if(dist[it] + 1 < dist[j])
                        {
                            q.push(j);
                            dist[j] = dist[it] + 1;
                        }
                    }
                }
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};
    
//     Runtime: 166 ms, faster than 54.28% of C++ online submissions for Shortest Distance After Road Addition Queries I.
// Memory Usage: 146.1 MB, less than 24.55% of C++ online submissions for Shortest Distance After Road Addition Queries I.
    
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         vector<vector<int>> adj(n+1);
//         for(int i = 0; i < n-1; i++)
//         {
//             adj[i].push_back(i+1);
//         }
        
//         vector<int> ans;
//         for(auto x : queries)
//         {
//             adj[x[0]].push_back(x[1]);
//             vector<int> dist(n, 1e9);
//             dist[0] = 0;
//             queue<int> q;
//             q.push(0);
//             while(!q.empty())
//             {
//                 int sz = q.size();
//                 for(int i = 0; i < sz; i++)
//                 {
//                     auto it = q.front();
//                     q.pop();
//                     for(auto j : adj[it])
//                     {
//                         if(dist[it] + 1 < dist[j])
//                         {
//                             q.push(j);
//                             dist[j] = dist[it] + 1;
//                         }
//                     }
//                 }
//             }
//             ans.push_back(dist[n-1]);
//         }
//         return ans;
//     }
// };