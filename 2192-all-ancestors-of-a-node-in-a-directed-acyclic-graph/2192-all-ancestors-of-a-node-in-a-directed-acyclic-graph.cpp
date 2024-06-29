class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(auto i : edges)
        {
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        
        queue<int> q;
        
        for(int i = 0; i < n; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        
        vector<set<int>> v(n);
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            for(auto i : adj[it])
            {
                // ans[i].push_back(it);
                v[i].insert(it);
                indegree[i]--;
                v[i].insert(v[it].begin(), v[it].end());
                // for(auto j : ans[it])
                    // ans[i].push_back(j);
                if(!indegree[i])
                    q.push(i);
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(auto j : v[i])
                ans[i].push_back(j);
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     sort(ans[i].begin(), ans[i].end());
        //     ans[i].erase(unique(ans[i].begin(), ans[i].end()), ans[i].end()); // must learn this method from javatpoint, Link -> https://www.javatpoint.com/cpp-algorithm-unique-function
        // }
        return ans;
    }
};