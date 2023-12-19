class Solution {
public:
    
//     Runtime: 45 ms, faster than 47.08% of C++ online submissions for Image Smoother.
// Memory Usage: 22 MB, less than 59.38% of C++ online submissions for Image Smoother.
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int sum = 0, count = 0;
                for(int k = -1; k <= 1; k++)
                {
                    for(int l = -1; l <= 1; l++)
                    {
                        int r = i + k, c = j + l;
                        if(r >= 0 && r < n && c >= 0 && c < m)
                        {
                            sum += img[r][c];
                            count++;
                        }
                    }
                }
                ans[i][j] = sum / count;
            }
        }
        return ans;
    }
};