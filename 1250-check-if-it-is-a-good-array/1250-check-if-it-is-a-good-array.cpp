class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        for(int i = 1; i < n; i++)
        {
            a = __gcd(a, nums[i]);
        }
        if(a == 1)
            return true;
        return false;
    }
};