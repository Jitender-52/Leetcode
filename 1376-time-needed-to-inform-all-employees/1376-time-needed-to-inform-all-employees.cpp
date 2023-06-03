class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        int head;
        for(int i = 0; i < n; i++)
        {
            if(manager[i] == -1)
            {
                head = i;
                continue;
            }
            adj[manager[i]].push_back(i);
        }
        
        auto bfs = [&](int src)
        {
            queue<pair<int,int>> q;
            q.push({src, informTime[src]});
            int ans = 0;
            while(!q.empty())
            {
                auto node = q.front();
                q.pop();
                for(auto i : adj[node.first])
                {
                    q.push({i, informTime[i] + node.second});
                }
                ans = max(ans, node.second);
            }
            return ans;
        };
        return bfs(head);        
    }
};