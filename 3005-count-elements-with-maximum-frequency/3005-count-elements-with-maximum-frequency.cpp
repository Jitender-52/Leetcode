class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count Elements With Maximum Frequency.
// Memory Usage: 19.5 MB, less than 42.86% of C++ online submissions for Count Elements With Maximum Frequency.
    
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums)
        {
            mp[i]++;
        }
        int maxi = 0;
        for(auto i : mp)
        {
            maxi = max(maxi, i.second);
        }
        int ans = 0;
        for(auto i : mp)
        {
            if(i.second == maxi)
                ans += i.second;
        }
        return ans;
    }
};