
class Graph {
public:    

    vector<vector<pair<int,int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n+1);
        for(auto i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        auto i = edge;
        adj[i[0]].push_back({i[1], i[2]});
    }
    
    int shortestPath(int node1, int node2) {
        set<pair<int,int>> st;
        vector<int> dist(101, 1e9);
        st.insert({0, node1});
        dist[node1] = 0;
        
        while(st.size())
        {
            auto it = st.begin();
            int wt = it->first;
            int node = it->second;
            st.erase(st.begin());
            for(auto i : adj[node])
            {
                int nnode = i.first;
                int w = i.second;
                if(dist[node] + w < dist[nnode])
                {
                    // st.erase({dist[nnode], nnode});
                    dist[nnode] = dist[node] + w;
                    st.insert({dist[nnode], nnode});
                }
            }
        }
        if(dist[node2] == 1e9)
            return -1;
        return dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */