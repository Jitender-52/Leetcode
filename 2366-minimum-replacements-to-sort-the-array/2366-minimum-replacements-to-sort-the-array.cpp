class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        for(int i = n-2; i >= 0; i--)
        {
            int a = nums[i+1];
            int parts = (nums[i] + nums[i+1] - 1) / a;
            ans += parts - 1;
            nums[i] = nums[i] / parts;
        }
        
        // for(int i = n-2; i >= 0; i--)
        // {
        //     int count = 1;
        //     bool check = false;
        //     int a = nums[i];
        //     if(nums[i] >= nums[i+1])
        //     {
        //         ans += nums[i] / nums[i+1];
        //         // count *= 2;
        //         check = true;
        //     }
        //     if(check)
        //     {
        //         if(a % 2 && nums[i] * 2 - 1 == nums[i+1])
        //         {
        //             ans--;
        //             nums[i] = nums[i] * 2 - 1;
        //         }
        //         else if(a % 2)
        //         {
        //             nums[i]--;
        //         }
        //     }
        // }
        return ans;
    }
};