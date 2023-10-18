class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n+1);
        for(auto v : relations)
        {
            indegree[v[1]]++;
            adj[v[0]].push_back(v[1]);
        }
        
        queue<pair<int,int>> q;
        vector<int> v(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            if(indegree[i] == 0)
            {
                v[i] = time[i-1];
                q.push({i, time[i-1]});
            }
        }
        
        int ans = 0;
        while(!q.empty())
        {
            auto node = q.front().first;
            ans = max(ans, q.front().second);
            q.pop();
            for(auto neighbour : adj[node])
            {
                indegree[neighbour]--;
                v[neighbour] = max(v[neighbour], v[node] + time[neighbour-1]);
                if(indegree[neighbour] == 0)
                {
                    q.push({neighbour, v[neighbour]});
                }
            }
        }
        // for(int i = 1; i <= n; i++)
        // {
        //     cout << i << " " << v[i] << endl;
        // }
        return ans;
    }
};