class Solution {
public:
    
//     Runtime: 56 ms, faster than 66.77% of C++ online submissions for Check If It Is a Good Array.
// Memory Usage: 29.4 MB, less than 37.74% of C++ online submissions for Check If It Is a Good Array.

    
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        for(int i = 0; i < n; i++)
        {
            a = __gcd(a, nums[i]);
            if(a == 1)
                return true;
        }
        return false;
    }
};