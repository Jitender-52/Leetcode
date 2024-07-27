class Solution {
public:
    
    
    vector<int> dijkstra(int n, vector<vector<vector<int>>> adj, int s)
    {
        set<pair<int, int>> st;
        vector<int> dist(n, 1e9);
    
        st.insert({0, s});
        dist[s] = 0;
    
        while (!st.empty())
        {
            auto it = st.begin();
            int d = it->first; // because it is a pointer if we want to access it using dot then use *before st.begin();
            int node = it->second;
            st.erase(it);
            for (auto i : adj[node])
            {
                int wt = i[1];
                int nnode = i[0];
                if (wt + d < dist[nnode])
                {
                    if (dist[nnode] != 1e9)
                        st.erase({dist[nnode], nnode});
                    dist[nnode] = wt + d;
                    st.insert({wt + d, nnode});
                }
            }
        }
        return dist;
    }
    
    long long minimumCost(string s, string t, vector<char>& o, vector<char>& c, vector<int>& p) {
        vector<vector<vector<int>>> adj(26);
        // dist.resize(26, 1e9);
        for(int i = 0; i < o.size(); i++)
        {
            adj[o[i] - 'a'].push_back({c[i] - 'a', p[i]});
        }
        // vector<int> dist = dijkstra(26, );
        
        vector<vector<int>> dist;
        for(int i = 0; i < 26; i++)
        {
            dist.push_back(dijkstra(26, adj, i));   
        }
        
        long long ans = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(dist[s[i] - 'a'][t[i] - 'a'] == 1e9)
                return -1;
            ans += (1LL * dist[s[i] - 'a'][t[i] - 'a']);
        }
        return ans;
        
    }
};