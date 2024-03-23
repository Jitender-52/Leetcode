class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int> (n, 20));
        for(auto i : edges)
        {
            auto u = i[0] - 1;
            auto v = i[1] - 1;
            adj[u][v] = adj[v][u] = 1;
        }
        
        // Floyd-Warshall
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        
        vector<int> ans(n-1, 0);
        for(int s = 0; s < (1 << n); s++)
        {
            int k = __builtin_popcount(s); // no. of nodes taken;
            int d = 0;
            int count = 0; // no. of edges between the node
            for(int i = 0; i < n; i++)
            {
                if(s & (1 << i))
                {
                    for(int j = i+1; j < n; j++)
                    {
                        if(s & (1 << j))
                        {
                            count += adj[i][j] == 1; // counting the connection b/w i and j(as it will form the subtree, there will be node b/w i and if g[i][j] == 1)
                            d = max(d, adj[i][j]);
                        }
                    }
                }
            }
            if(d > 0 && count == k-1) // to form a subtree b/w n nodes will have n-1 edges  so here are k nodes in this.
            {
                ans[d-1]++;
            }
        }
        return ans;
    }
};