class Solution {
public:
    
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 1, ans = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1])
                count++;
            else
            {
                ans += (count * (count - 1)) / 2;
                count = 1;
            }
        }
        ans += (count * (count - 1)) / 2;
        return ans;
    }
};
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs.
// Memory Usage: 7.7 MB, less than 7.10% of C++ online submissions for Number of Good Pairs.
    
//     int numIdenticalPairs(vector<int>& nums) {
//         int n = nums.size();
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//         }
//         int ans = 0;
//         for(auto i : mp)
//         {
//             ans += (i.second * (i.second - 1)) / 2;
//         }
//         return ans;
//     }
// };