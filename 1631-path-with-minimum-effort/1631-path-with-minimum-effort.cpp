class Solution {
public:
    
//     Runtime: 190 ms, faster than 45.64% of C++ online submissions for Path With Minimum Effort.
// Memory Usage: 37.2 MB, less than 17.95% of C++ online submissions for Path With Minimum Effort.
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        set<pair<int, pair<int,int>>> st;
        st.insert({0, {0, 0}});
        dist[0][0] = 0;
        
        auto isValid = [&](int r, int c)
        {
            return (r >= 0 && r < n && c >= 0 && c < m);  
        };
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};    
        
        while(!st.empty())
        {
            auto it = *st.begin();
            st.erase(st.begin());
            int r = it.second.first;
            int c = it.second.second;
            int d = it.first; 
            
            // New part added i.e. return if answer is found i.e. n-1, m-1 is reached. Let's check it works or not;
            if(r == n-1 && c == m-1)
                return d;
            
            for(int i = 0; i < 4; i++)
            {
                // cout << r << " " << c << endl;
                // return 0;
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(isValid(nr, nc))
                {
                    int a = max(d, abs(heights[r][c]-heights[nr][nc]));
                    if(a < dist[nr][nc])
                    {
                        dist[nr][nc] = a;
                        st.insert({a, {nr, nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};