class Solution {
public:
    
    vector<vector<int>> adj;
    vector<int> ans, vis, child;
    int N;
    
    void dfs1(int src, int length)
    {
        vis[src] = 1;
        ans[0] += length;
        length++;
        for(auto &node : adj[src])
        {
            if(!vis[node])
            {
                dfs1(node, length);
                child[src] += child[node];
            }
        }
        child[src] += 1;
    }
    
    void dfs2(int src)
    {
        vis[src] = 1;
        for(auto node : adj[src])
        {
            if(!vis[node])
            {
                ans[node] = ans[src] - child[node] +  N - child[node];
                dfs2(node);
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        adj.resize(n);
        ans.resize(n);
        vis.resize(n);
        child.resize(n);
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs1(0, 0);
        for(int i = 0; i < n; i++)
            vis[i] = 0;
        dfs2(0);
        return ans;
    }
};