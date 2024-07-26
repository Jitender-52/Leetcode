class Solution {
public:
    
//     Runtime: 24 ms, faster than 74.13% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.
// Memory Usage: 16.2 MB, less than 23.89% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.
    
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> v(n, vector<int> (n, 1e9));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    v[i][j] = 0;
            }
        }
        
        for(auto i : edges)
        {
            int a = i[0], b = i[1], wt = i[2];
            v[a][b] = wt;
            v[b][a] = wt;
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(v[i][k] + v[k][j] < v[i][j])
                        v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(v[i][j] != 0 && v[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            ans.push_back({count, i});
        }
        
        sort(ans.begin(), ans.end(), comp);
        return ans[0][1];
    }
};