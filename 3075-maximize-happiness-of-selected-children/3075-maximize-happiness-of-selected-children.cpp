class Solution {
public:
    
//     Runtime: 211 ms, faster than 20.94% of C++ online submissions for Maximize Happiness of Selected Children.
// Memory Usage: 108.6 MB, less than 29.47% of C++ online submissions for Maximize Happiness of Selected Children.

    
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin(), happiness.rend());
        int count = 0;
        for(auto i : happiness)
        {
            if(k <= 0)
                break;
            ans += 1LL * max(0, i - count);
            count++;
            k--;
        }
        return ans;
    }
};