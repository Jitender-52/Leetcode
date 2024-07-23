class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        for(auto i : nums)
            mp[i]++;
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mp[a] == mp[b])
                return a > b;
            return mp[a] < mp[b];
        });
        return nums;
    }
};
    
    
//     Runtime: 3 ms, faster than 89.91% of C++ online submissions for Sort Array by Increasing Frequency.
// Memory Usage: 14.6 MB, less than 78.88% of C++ online submissions for Sort Array by Increasing Frequency.
    
//     vector<int> frequencySort(vector<int>& nums) {
//         map<int,int> mp;
//         for(auto i : nums)
//             mp[i]++;
//         vector<pair<int,int>> v;
//         for(auto i : mp)
//             v.push_back({i.second, i.first});
//         sort(v.begin(), v.end(), [&](pair<int,int> &a, pair<int,int> &b){
//                 if(a.first == b.first)
//                     return a.second > b.second;
//                 return a.first < b.first;
//         });
//         vector<int> ans;
//         for(auto p : v)
//         {
//             for(int i = 0; i < p.first; i++)
//                 ans.push_back(p.second);
//         }
//         return ans;
//     }
// };