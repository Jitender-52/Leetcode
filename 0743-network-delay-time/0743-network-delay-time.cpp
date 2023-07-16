class Solution {
public:
    
    // we can also use dijkastra's algorithm because there is no negative edge.
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n+1);
        
        for(auto i : times)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        vector<int> dist(n+1, 1e9);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for(auto i : adj[node])
            {
                auto nnode = i[0];
                auto wt = i[1];
                if(d + wt < dist[nnode])
                {
                    dist[nnode] = d + wt;
                    pq.push({d + wt, nnode});
                }
            }
        }
        dist[0] = 0;
        int ans = *max_element(dist.begin(), dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};
        
        
//     Runtime: 1502 ms, faster than 5.00% of C++ online submissions for Network Delay Time.
// Memory Usage: 275.3 MB, less than 5.22% of C++ online submissions for Network Delay Time.
    
        
        // Bellman Ford algorithm
        
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<int> dist(n+1, 1e9);
//         dist[k] = 0;
//         for(int i = 0; i < n; i++)
//         {
//             for(auto i : times)
//             {
//                 int node = i[0], nnode = i[1], wt = i[2];
//                 if(dist[node] + wt < dist[nnode])
//                     dist[nnode] = dist[node] + wt;
//             }
//         }
//         dist[0] = 0;
//         int ans = *max_element(dist.begin(), dist.end());
//         return ans == 1e9 ? -1 : ans;
//     }
// };