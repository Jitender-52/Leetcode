class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, sum = 0;
        for(auto i : gain)
            ans = max(ans, sum += i);
        return ans;
    }
};