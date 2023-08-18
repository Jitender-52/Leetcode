class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        
        vector<vector<int>> edges(n, vector<int> (n, 0));
        for(auto e : roads)
        {
            indegree[e[0]]++;
            indegree[e[1]]++;
            edges[e[0]][e[1]]++;
            edges[e[1]][e[0]]++;
        }
        
        // can be reduced to low time complexity but here constraints are less
        
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    ans = max(ans, indegree[i] + indegree[j] - edges[i][j]);
                }
            }
        }
        return ans;
        
        // vector<pair<int,int>> v;
        // for(int i = 0; i < n; i++)
        // {
        //     v.push_back({indegree[i], i});
        // }
        
//         sort(v.rbegin(), v.rend());
        
//         int ans = v[0].first + v[1].first; 
        
//         int a = v[0].second, b = v[1].second;
//         for(auto e : roads)
//         {
//             if(e[0] == a && e[1] == b || e[1] == a && e[0] == b)
//                 ans--; // subtracting common road
//         }        
//         return ans;
    }   
};