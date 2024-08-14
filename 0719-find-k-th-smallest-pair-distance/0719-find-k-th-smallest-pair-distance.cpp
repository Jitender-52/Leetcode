class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(1e6+1, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
                v[abs(nums[i] - nums[j])]++;
        }
        for(int i = 0; i <= 1e6; i++)
        {
            k -= v[i];
            if(k <= 0)
                return i;
        }
        return 0;
    }
};