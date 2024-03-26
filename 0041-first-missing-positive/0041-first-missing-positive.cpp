class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1e8;
        }
        for(int i = 0; i < n; i++)
        {
            // cout << i << " " << nums[i] << endl;
            if(abs(nums[i]) > n)
                continue;
            int idx = abs(nums[i]);
            if(nums[idx-1] > 0)
                nums[idx-1] *= -1;
        }
        // cout << endl;
        
        for(int i = 0; i < n; i++)
        {
            // cout << nums[i] << " ";
            if(nums[i] > 0)
                return i+1;
        }
        // cout << endl;
        return n+1;
    }
};