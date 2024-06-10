class Solution {
public:
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