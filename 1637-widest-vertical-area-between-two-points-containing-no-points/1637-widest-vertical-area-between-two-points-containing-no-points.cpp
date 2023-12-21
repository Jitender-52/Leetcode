class Solution {
public:
    
//     Runtime: 255 ms, faster than 29.40% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.
// Memory Usage: 66.7 MB, less than 62.68% of C++ online submissions for Widest Vertical Area Between Two Points Containing No Points.
    
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 1; i < points.size(); i++) 
        {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }
        return ans;
    }
};