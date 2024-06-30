class Solution {
public:
    
//     Runtime: 126 ms, faster than 37.50% of C++ online submissions for Find the Maximum Length of Valid Subsequence I.
// Memory Usage: 94.5 MB, less than 75.00% of C++ online submissions for Find the Maximum Length of Valid Subsequence I.
// Next challenges
    
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        int ans = 0, count = 0;
        int totalOdd = 0, totalEven = 0;
        for(int i = 0; i < n; i++) // Either only odd or even 
        {
            totalOdd += nums[i] % 2;
            totalEven += !(nums[i] % 2);
        }
        ans = max(totalOdd, totalEven);
        ans = max(ans, count);
            
        int a = 1, count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++) // odd, even, odd, even....
        {
            if(nums[i] % 2 == a)
            {
                count1++;
                a ^= 1;
            }
        }
        a = 0;
        for(int i = 0; i < n; i++) // even, odd, even, odd....
        {
            if(nums[i] % 2 == a)
            {
                count2++;
                a ^= 1;
            }
        }
        ans = max(ans, max(count1, count2));
        return ans;
    }
};