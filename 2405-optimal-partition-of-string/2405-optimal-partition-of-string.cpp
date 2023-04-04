class Solution {
public:
    
//     Runtime: 253 ms, faster than 28.98% of C++ online submissions for Optimal Partition of String.
// Memory Usage: 72.1 MB, less than 8.67% of C++ online submissions for Optimal Partition of String.
    
    int partitionString(string s) {
        map<char,int> mp;
        int ans = 1;
        for(auto i : s)
        {
            if(mp.find(i) != mp.end())
            {
                ans++;
                mp.clear();
            }
            mp[i]++;
        }
        return ans;
    }
};