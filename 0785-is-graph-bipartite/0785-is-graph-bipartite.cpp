class Solution {
public:
     bool bipartiteDfs(int node, vector<vector<int>> adj, int color[])
{
    if (color[node] == -1)
    {
        color[node] = 1;
    }

    for (auto i : adj[node])
    {
        if (color[i] == -1)
        {
            color[i] = 1 - color[node];
            if (!bipartiteDfs(i, adj, color))
            {
                return false;
            }
        }
        else if (color[node] == color[i]) // If we will use this condition first then it will take less time to run due to less number of recursive calls
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    int color[n];
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (!bipartiteDfs(i, adj, color))
        {
            return false;
        }
    }
    return true;
}
};