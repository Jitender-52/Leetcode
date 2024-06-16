class Solution{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long x = 1;
        int ans = 0;
        int i = 0;

        while(x <= n)
        {
            if (i < nums.size() && nums[i] <= x)
            {
                x += nums[i];
                i++;
            }
            else
            {
                x *= 2;
                ans++;
            }
        }
        return ans;
    }
};