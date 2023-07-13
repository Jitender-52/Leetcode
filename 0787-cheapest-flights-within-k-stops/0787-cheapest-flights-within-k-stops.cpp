class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> cost(n, 1e9);
        queue<pair<int,int>> q;
        q.push({0, src});
        cost[src] = 0;
        k++; // because we need to count the stops starting will not be counted as a stop
        while(k-- && !q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto c = q.front().first;
                auto node = q.front().second;
                q.pop();
                for(auto i : adj[node])
                {
                    int nnode = i[0];
                    int wt = i[1];
                    if(c + wt < cost[nnode])
                    {
                        cost[nnode] = c + wt;
                        q.push({c + wt, nnode});
                    }
                }
            }
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};
    
    
    // Wrong Answer
    
//         int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//             vector<vector<vector<int>>> adj(n);
//             for(auto i : flights)
//             {
//                 adj[i[0]].push_back({i[1], i[2]});
//             }
            
//             vector<int> cost(n, 1e9);
//             set<pair<int,pair<int,int>>> st;
//             cost[src] = 0;
//             st.insert({0, {0, src}});
            
//             while(!st.empty())
//             {
//                 auto it = *st.begin();
//                 st.erase(st.begin());
//                 int c = it.first;
//                 int stops = it.second.first;
//                 int node = it.second.second;
//                 for(auto i : adj[node])
//                 {
//                     int nnode = i[0];
//                     int wt = i[1];
//                     if(stops <= k && c + wt < cost[nnode])
//                     {
//                         cost[nnode] = c + wt;
//                         st.insert({c + wt, {stops + 1, nnode}});
//                     }
//                 }
//             }
            
//             // for(int i = 0; i < n; i++)
//             // {
//             //     cout << cost[i] << " ";
//             // }
//             // cout << endl;
            
//             if(cost[dst] == 1e9)
//                 return -1;
//             return cost[dst];
//         }
// };
    
    
//     Runtime: 32 ms, faster than 59.58% of C++ online submissions for Cheapest Flights Within K Stops.
// Memory Usage: 13.1 MB, less than 85.13% of C++ online submissions for Cheapest Flights Within K Stops
    
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<pair<int, int>>> adj(n);
//         for (auto& e : flights) {
//             adj[e[0]].push_back({e[1], e[2]});
//         }
//         vector<int> dist(n, numeric_limits<int>::max());
//         queue<pair<int, int>> q;
//         q.push({src, 0});
//         int stops = 0;

//         while (stops <= k && !q.empty()) {
//             int sz = q.size();
//             // Iterate on current level.
//             while (sz--) {
//                 auto [node, distance] = q.front();
//                 q.pop();
//                 // Iterate over neighbors of popped node.
//                 for (auto& [neighbour, price] : adj[node]) {
//                     if (price + distance >= dist[neighbour]) continue;
//                     dist[neighbour] = price + distance;
//                     q.push({neighbour, dist[neighbour]});
//                 }
//             }
//             stops++;
//         }
//         return dist[dst] == numeric_limits<int>::max() ? -1 : dist[dst];
//     }
// };