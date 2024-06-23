class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double ans = 1e9;
        sort(nums.begin(), nums.end());
        int i = 0, j = n-1;
        while(i < j)
        {
            ans = min(ans, (double)(nums[i] + nums[j]) / 2.0);
            i++;
            j--;
        }
        return ans;
    }
};