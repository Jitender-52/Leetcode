class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            int i = mid;
            if(i % 2 == 1)
            {
                 if(i + 1 < n && nums[i] == nums[i+1])
                 {
                     right = mid - 1;
                 }
                 else if(i > 0 && nums[i] == nums[i-1])
                 {
                     left = mid + 1;
                 }
                 else
                 {
                     return nums[mid];
                 }
            }
            else
            {
                if(i + 1 < n && nums[i] == nums[i+1])
                {
                    left = mid + 1;
                }
                else if(i > 0 && nums[i] == nums[i-1])
                {
                    right = mid  - 1;
                }
                else
                {
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};