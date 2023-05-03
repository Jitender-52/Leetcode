class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1, mp2;
//         for(auto i : nums1)
//         {
//             mp1[i] = 1;
//             mp2[i] = 1;
//         }
//         for(auto i : nums2)
//         {
//             mp1[i] = 0;
//             if(mp2[i] == 1)
//                 mp2[i] = 0;
//             else
//                 mp2[i] = 2;
//         }
        
        for(auto i : nums1)
        {
             mp1[i] = 1;
        }
        for(auto i : nums2)
        {
            mp1[i] = 0;
            mp2[i] = 1;
        }
        for(auto i : nums1)
        {
            mp2[i] = 0;
        }
        
        vector<vector<int>> v(2);
        for(auto i : mp1)
        {
            if(i.second == 1)
                v[0].push_back(i.first);
        }
        for(auto i : mp2)
        {
            if(i.second == 1)
                v[1].push_back(i.first);
        }
        return v;
    }
};