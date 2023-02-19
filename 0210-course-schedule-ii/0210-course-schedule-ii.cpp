class Solution {
public:
    
    bool isCycle(int src, vector<int> &vis, vector<int> &dfs, vector<vector<int>> &adj)
    {
        vis[src] = 1;
        dfs[src] = 1;
        
        for(auto i : adj[src])
        {
            if(vis[i] && dfs[i])
                return true;
            else if(!vis[i])
            {
                if(isCycle(i, vis, dfs, adj))
                    return true;
            }
        }
        dfs[src] = false;
        return false;
    }
    
    // void topologicalSort(int src, vector<int> &vis, vector<vector<int>> adj, stack<int> &st)
    // {
    //     vis[src] = 1;
    //     for(auto i : adj[src])
    //     {
    //         if(!vis[i])
    //         {
    //             topologicalSort(src, vis, adj, st);
    //         }
    //     }
    //     st.push(src);
    // }
    
    
void topologicalSort(int src, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    // int n = adj->size();
    // if (vis[src])
    //     return;

    vis[src] = true;
    for (auto i : adj[src])
    {
        if (!vis[i])
            topologicalSort(i, vis, adj, st);
    }
    st.push(src);
}
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        
        int m = p.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++)
        {
            adj[p[i][0]].push_back(p[i][1]);
        }
        
        vector<int> v;
        vector<int> vis(n, 0);
        vector<int> dfs(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(isCycle(i, vis, dfs, adj))
                    return v;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            vis[i] = false;
        }
        
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                topologicalSort(i, vis, adj, st);
            }
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse(v.begin(), v.end());
        return v;
    }
};