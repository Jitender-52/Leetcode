class Solution {
public:

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) 
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
        q.push({1, 1});
        dist1[1] = 0;

        while (!q.empty()) 
        {
            auto [node, freq] = q.front();
            q.pop();

            int timeTaken = freq == 1 ? dist1[node] : dist2[node];
            if ((timeTaken / change) % 2) 
                timeTaken = change * (timeTaken / change + 1) + time;
            else 
                timeTaken = timeTaken + time;

            for (auto& neighbor : adj[node])
            {
                if (dist1[neighbor] == -1) 
                {
                    dist1[neighbor] = timeTaken;
                    q.push({neighbor, 1});
                } 
                else if (dist2[neighbor] == -1 && dist1[neighbor] != timeTaken) 
                {
                    if (neighbor == n)
                        return timeTaken;
                    dist2[neighbor] = timeTaken;
                    q.push({neighbor, 2});
                }
            }
        }
        return 0;
    }
};
    
//     set<long long> ans;
//     // vector<int> vis(10001);
//     int vis[10001];
    
//     void solve(int src, int parent, long long count, vector<vector<int>> &adj, int time, int change)
//     {
//         int n = adj.size();
//         cout << src << endl;
//         if(src == n)
//             return;
//             // ans.insert(count);
//         if(vis[src])
//             return;
//         vis[src] = 1;
//         for(auto i : adj[src])
//         {
//             if(i != parent && !vis[i])
//             {
//                 if((count / change) % 2 == 1)
//                     solve(i, src, count * ((count / change) + 1) + time, adj, time, change);
//                 else
//                     solve(i, src, count + time, adj, time, change);
//             }
//         }
//     }
    
//     int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
//         vector<vector<int>> adj(n+1);
//         for(auto i : edges)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         long long count = 0;
//         solve(1, -1, count, adj, time, change);
//         if(ans.size() == 1)
//             return *ans.begin();
//         ans.erase(ans.begin());
//         return *ans.begin();
//     }
// };