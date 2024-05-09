class Solution {
public:
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