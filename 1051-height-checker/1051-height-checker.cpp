class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Height Checker.
// Memory Usage: 10.2 MB, less than 10.73% of C++ online submissions for Height Checker.
    
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> v = heights;
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans += v[i] != heights[i];
        return ans;
    }
};