class Solution {
public:
    
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            double x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    continue;
                double x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                double d = (sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))); // written y1 - y1 instead of y2 - y1;
                // cout << d << endl;
                if(d <= r1)
                {
                    adj[i].push_back(j);
                }
            }
        }
        
        auto bfs = [=](int src)
        {
            int count = 0;
            queue<int> q;
            q.push(src);
            vector<int> vis(n, 0);
            vis[src] = 1;
            while(!q.empty())
            {
                src = q.front();
                q.pop();
                for(auto i : adj[src])
                {
                    if(!vis[i])
                    {
                        vis[i] = 1;
                        q.push(i);
                    }
                }
                count++;
            }
            return count;
        };
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, bfs(i));
        }
        return ans;
    }
};