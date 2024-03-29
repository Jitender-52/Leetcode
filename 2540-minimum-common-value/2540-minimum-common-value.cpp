class Solution {
public:
    
//     Runtime: 199 ms, faster than 5.09% of C++ online submissions for Minimum Common Value.
// Memory Usage: 84.7 MB, less than 5.15% of C++ online submissions for Minimum Common Value.
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[nums1[i]] = 1;
        }
        
        for(int i = 0; i < m; i++)
        {
            if(mp[nums2[i]] == 1)
            mp[nums2[i]] = 2;
        }
        for(auto i : mp)
        {
            if(i.second == 2)
                return i.first;
        }
        return -1;
    }
};