class Solution {
public:
    
//     Runtime: 283 ms, faster than 6.67% of C++ online submissions for Longest Square Streak in an Array.
// Memory Usage: 136.1 MB, less than 9.65% of C++ online submissions for Longest Square Streak in an Array.
    
    int longestSquareStreak(vector<int>& nums) {
        long long n = nums.size();
        
        map<long long,long long> mp;
        for(long long i = 0; i < n; i++)
            mp[nums[i]]++;
        
        int ans = 0;
        for(auto i : mp)
        {
            long long a = i.first;
            int count = 1;
            while(mp[a * a] > 0)
            {
                count++;
                mp.erase(a * a);
                a = a * a;
            }
            if(mp[a * a] == 0)
                mp.erase(a * a);
            ans = max(ans, count);
        }
        if(ans <= 1)
            return -1;
        return ans;        
    }
};