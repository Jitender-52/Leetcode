class Solution {
public:
    
//     Runtime: 6 ms, faster than 28.46% of C++ online submissions for Find the Highest Altitude.
// Memory Usage: 8 MB, less than 54.63% of C++ online submissions for Find the Highest Altitude.

    
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;
        for(auto i : gain)
            ans = max(ans, sum += i);
        return ans;
    }
};