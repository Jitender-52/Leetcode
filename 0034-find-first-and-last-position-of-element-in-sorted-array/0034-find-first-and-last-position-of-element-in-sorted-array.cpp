class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        bool check = false;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(nums[mid] == target)
                check = true;
            if(nums[mid] <= target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(!check)
            return {-1, -1};
        int a = l - 1;
        l = 0, r = n-1;
        while(l <= r)
        {
            int mid = (l + r) /2 ;
            if(nums[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return {r + 1, a};
    }
};