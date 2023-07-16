class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        for(int i = 0; i < n; i++)
        {
            for(auto i : times)
            {
                int node = i[0], nnode = i[1], wt = i[2];
                if(dist[node] + wt < dist[nnode])
                    dist[nnode] = dist[node] + wt;
            }
        }
        dist[0] = 0;
        int ans = *max_element(dist.begin(), dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};