class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = 1e9;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            ans = min(ans, nums[mid]);
            if(nums[mid] == nums[low] && nums[mid] == nums[high])
            {
                low++;
                high--;
            }
            else if(nums[mid] <= nums[high])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
        // cout << low << " " << high << endl;
        // return nums[high + 1];
    }
};