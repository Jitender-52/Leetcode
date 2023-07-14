//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
    // Must use long long everyWhere because of constraints
    
    const int mod = 1e9 + 7;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<long long>>> adj(n);
        for(auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        
        vector<long long> dist(n, 1e18); // instead of 1e9 should use 1e18 because t=[1,1e9];
        set<pair<long long, long long>> st; // pair{src, dist};
        st.insert({0, 0});
        dist[0] = 0;
        
        while(!st.empty())
        {
            auto node = st.begin()->first;
            auto d = st.begin()->second;
            st.erase(st.begin());
            for(auto i : adj[node])
            {
                auto nnode = i[0];
                auto wt = i[1];
                if(d + wt < dist[nnode])
                {
                    dist[nnode] = d + wt;
                    st.insert({nnode, d + wt});
                }
            }
        }
        
        vector<long long> ways(n, 0);
        ways[0] = 1;
        
        // set<pair<int, int>> st; // pair of {dist, src}
        // Declared already and already begin empty
        
        for(int i = 0; i < n; i++)
        {
            st.insert({dist[i], i});
        }
        
        for(auto i : st)
        {
            auto node = i.second;
            for(auto i : adj[node])
            {
                auto nnode = i[0];
                auto wt = i[1];
                if(dist[node] + wt == dist[nnode])
                    (ways[nnode] += ways[node]) %= mod; // Doing misatke here not taking mod after adding taking only before
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends