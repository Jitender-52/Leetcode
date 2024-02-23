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
    
//     Need to check why its giving wrong answer
    
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<vector<vector<int>>> adj(n);
//         for(auto i : flights)
//             adj[i[0]].push_back({i[1], i[2]});
//         queue<pair<int, int>> q;
//         vector<int> dist(n, 1e9);
//         q.push({0, src});
//         dist[src] = 0;
//         k++;
//         while(q.size() && k--)
//         {
//             int sz = q.size();
//             for(int j = 0; j < sz; j++)
//             {
//                 auto p = q.front();
//                 // if(p.first != dist[p.second])
//                 // {
//                 //     cout << p.second << endl;
//                 //     cout << "HII" << endl;
//                 // }
//                 q.pop();
//                 // cout << p.second << " " << p.first << " -> " << endl;
//                 for(auto i : adj[p.second])
//                 {
//                     if(dist[p.second] + i[1] < dist[i[0]])
//                     {
//                         dist[i[0]] = dist[p.second] + i[1];
//                         q.push({dist[i[0]], i[0]});
//                         // cout << i[0] << " " << dist[i[0]] << endl;
//                     }
//                 }
//             }
//             cout << endl;
//         }
//         for(auto i : dist)
//             // cout << i << " ";
//         cout << endl;
//         return dist[dst] == 1e9 ? -1 : dist[dst];
//     }
// };

   // 3<-2<-0
   //    | 1<-|