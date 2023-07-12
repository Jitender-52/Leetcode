//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
      vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<vector<vector<int>>> adj(n+1);
        for(auto i : edges)
        {
            int x = i[0], y = i[1], z = i[2];
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1, 1e9), parent(n+1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
        
        pq.push({0, 1});
        dist[1] = 0;
            
        while(!pq.empty())
        {
            auto node = pq.top().second;
            auto d = pq.top().first;
            // cout << node << endl;
            pq.pop();
            for(auto it : adj[node])
            {
                auto nnode = it[0];
                auto wt = it[1];
                if(d + wt < dist[nnode])
                {
                    pq.push({d + wt, nnode});
                    dist[nnode] = d + wt;
                    parent[nnode] = node;
                }
            }
        }
        
        vector<int> ans;
        if(dist[n] == 1e9)
            return {-1};
        int i = n;
        while(parent[i] != i)
        {
            ans.push_back(i);
            i = parent[i];
        }
        ans.push_back(1); // because only the source will be having the parent itself so we need to add it in the last;
        reverse(ans.begin(), ans.end()); // becasue we storing the path from n to 1;
        return ans; // mybad forgot to return the answer
    }
};
  
  
  
//     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
//         // Code here
        
//         vector<vector<vector<int>>> adj(n+2);
//         for(auto i : edges)
//         {    
//             int x = i[0], y = i[1], wt = i[2];
//             adj[x].push_back({y, wt});
//             adj[y].push_back({x, wt});
//         }
        
//         // set<pair<int, int>> st;
//         // vector<int> dist(n+1, 1e9);
    
//         // st.insert({0, src});
//         // dist[src] = 0;
    
//         // while (!st.empty())
//         // {
//         //     auto it = st.begin();
//         //     int d = it->first; // because it is a pointer if we want to access it using dot then use *before st.begin();
//         //     int node = it->second;
//         //     st.erase(it);
//         //     for (auto i : adj[node])
//         //     {
//         //         int wt = i[1];
//         //         int nnode = i[0];
//         //         if (wt + d < dist[nnode])
//         //         {
//         //             if (dist[nnode] != 1e9)
//         //                 st.erase({dist[nnode], nnode});
//         //             dist[nnode] = wt + d;
//         //             st.insert({wt + d, nnode});
//         //         }
//         //     }
//         // }

        
//         map<int, vector<int>> mp;
//         vector<int> dis(n+1, 1e9);
//         set<pair<int,int>> st;
//         st.insert({0, 1});
//         dis[1] = 0;
//         mp[1].push_back(1);
        
//         while(!st.empty())
//         {
//             auto it = *st.begin();
//             int node = it.second;
//             int d = it.first;
//             st.erase(it);
//             for(auto i : adj[node])
//             {
//                 int wt = i[1];
//                 int nnode = i[0];
//                 if(wt + d < dis[nnode])
//                 {
//                     if(dis[nnode] != 1e9)
//                         st.erase({dis[nnode], nnode});
//                     dis[nnode] = wt + d;
//                     st.insert({wt+d, nnode});
//                     mp[nnode] = mp[node];
//                     mp[nnode].push_back(nnode);
//                 }
//             }
//         }
//         if(mp[n].size() == 0)
//             return {-1};
//         return mp[n];
//         // dis.erase(dis.begin());
//         // dis.erase(dis.begin());
//         // return dis;
//     }
// };

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends