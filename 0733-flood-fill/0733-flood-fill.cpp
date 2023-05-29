class Solution {
public:
    
//     Runtime: 12 ms, faster than 38.85% of C++ online submissions for Flood Fill.
// Memory Usage: 14.3 MB, less than 16.72% of C++ online submissions for Flood Fill.
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int c1 = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        
        auto isValid = [&](int r, int c)
        {
            return (r >= 0 && r < n && c >= 0 && c < m);
        };
        
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
    
        // vector<vector<int>> vis(n, vector<int> (m , 0));
        // vis[sr][sc] = 1;
        
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dx[i];
                int nc = c + dy[i];
                // cout << nr << " " << nc << endl;
                // if(isValid(nr, nc) && image[nr][nc] == c1 && !vis[nr][nc])
                if(isValid(nr, nc) && image[nr][nc] == c1 && image[nr][nc] != color)
                {
                    image[nr][nc] = color;
                    // vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};