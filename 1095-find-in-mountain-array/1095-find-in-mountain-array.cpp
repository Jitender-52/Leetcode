/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int low = 1, high = n-2;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mountainArr.get(mid) > mountainArr.get(mid + 1))
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        int x = low;
        
        low = 0, high = x;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mountainArr.get(mid) > target)
                high = mid  - 1;
            else
                low = mid + 1;
        }
        
        if(high >= 0 && mountainArr.get(high) == target)
            return high;
        
        low = x + 1, high = n-1;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(mountainArr.get(mid) > target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        
        if(low < n && mountainArr.get(low) == target)
            return low;
        return -1;
    }
};