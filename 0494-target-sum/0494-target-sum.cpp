class Solution {
public:
    
    int memo(int ind, int target, vector<int> &arr) {
      if (ind == 0) 
      {
        if(target == 0 && arr[0] == 0) 
            return 2;
        // if(target == 0) 
        //     return 1;
        if (arr[ind] + target == 0)
            return 1;
        if (arr[ind] - target == 0)
            return 1;
        return 0;
      }
        
      int  plus = memo(ind - 1, target - arr[ind], arr);
      int neg = memo(ind - 1, (target + arr[ind]), arr);
      return plus + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return memo(n-1, target, nums);
    }
};
    
    
    
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//     }
// };