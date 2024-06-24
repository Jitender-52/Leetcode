class Solution {
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        vector<int> v(nums.size(), false);
        int count = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i >= k && v[i - k])
            {
                count--;
            }
            if (count % 2 == nums[i])
            {
                if (i + k > nums.size())
                    return -1;
                count++;
                v[i] = true;
                ans++;
            }
        }
        return ans;
    }
};