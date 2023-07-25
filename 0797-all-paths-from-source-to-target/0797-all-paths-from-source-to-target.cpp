class Solution {
public:
    
    void dfs(int src, vector<vector<int>> &adj, vector<int> &v, vector<vector<int>> &ans)
    {
        int n = adj.size();
        v.push_back(src);
        if(src == n-1)
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        for(auto i : adj[src])
        {
            dfs(i, adj, v, ans);
        }
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            for(auto j : graph[i])
                adj[i].push_back(j);
        }
        
        vector<vector<int>> ans;
        vector<int> v;
        dfs(0, adj, v, ans);
        return ans;
    }
};