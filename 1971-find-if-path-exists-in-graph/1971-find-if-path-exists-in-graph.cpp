class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)     {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            if(node == destination)
                return true;
            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};