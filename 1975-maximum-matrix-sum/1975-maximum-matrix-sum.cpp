class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Matrix Sum.
// Memory Usage: 42.9 MB, less than 8.11% of C++ online submissions for Maximum Matrix Sum.
    
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0, mini = INT_MAX, count = 0;
        for(auto v : matrix)
        {
            for(auto i : v)
            {
                ans += abs(i);
                count += i < 0;
                mini = min(mini, 1LL * abs(i));
            }
        }
        if(count % 2)
            ans -= 2 * mini;
        return ans;
    }
};