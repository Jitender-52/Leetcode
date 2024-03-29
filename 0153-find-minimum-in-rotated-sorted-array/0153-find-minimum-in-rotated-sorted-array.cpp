class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int left = 0, right = n-1;

        if(nums[n-1] > nums[0])
            return nums[0];
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            // cout << mid << " ";
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid] > nums[0])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};