class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = 0;
        int left = 1, right = n-2;
        
        if(n == 1)
        {
            if(nums[0] == target)
                return 0;
            return -1;
        }
        
        if(nums[n-1] < nums[0])
            pivot = n-1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[mid + 1])
            {
                pivot = mid + 1;
                break;
            }
            if(nums[mid] < nums[mid - 1])
            {
                pivot = mid;
                break;
            }
            
            if(nums[mid] > nums[0])
                left = mid + 1;
            else
                 right = mid - 1;
        }
        
        // cout << pivot << endl;
        
        if(target >= nums[0] && target > nums[n-1])
        {
            left = 0;
            right = pivot;
        }
        else
        {
            left = pivot;
            right = n-1;
        }
        
        // cout << left << " " << right << endl;
        
        // if(target >= nums[pivot])
        // {
        //     left = pivot;
        //     right = n-1;
        // }
        // else
        // {
        //     left = 0;
        //     right = pivot - 1;
        // }
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
            else
                return mid;
        }
        return -1;
    }
};