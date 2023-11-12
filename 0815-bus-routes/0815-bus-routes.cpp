class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target)
            return 0;
        map<int, vector<int>> adj;
        for(int i = 0; i < n; i++)
        {
            for(auto it : routes[i])
                adj[it].push_back(i);
        }
        
        vector<int> vis(n);
        queue<int> q;
        for(auto i : adj[source])
        {
            q.push(i);
            vis[i] = 1;
        }
        
        int ans = 1;
        // cout << q.size() << endl;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto bus_number = q.front();
                // cout << bus_number << " ";
                q.pop();
                for(auto it : routes[bus_number])
                {
                    if(it == target)
                        return ans;
                    for(auto node : adj[it])
                    {
                        if(!vis[node])
                        {
                            // cout << node <<  " "; 
                            vis[node] = 1;
                            q.push(node);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};