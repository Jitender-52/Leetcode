class Solution {
public:
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
            if(mp[groupSizes[i]].size() == groupSizes[i])
            {
                ans.push_back(mp[groupSizes[i]]);
                mp[groupSizes[i]] = {};
            }
        }
        return ans;
    }
};
    
    
//     Runtime: 14 ms, faster than 35.21% of C++ online submissions for Group the People Given the Group Size They Belong To.
// Memory Usage: 13.1 MB, less than 66.73% of C++ online submissions for Group the People Given the Group Size They Belong To.
    
//     vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
//         int n = groupSizes.size();
//         map<int, vector<int>> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[groupSizes[i]].push_back(i);
//         }
        
//         vector<vector<int>> ans;
//         vector<int> v;
//         for(auto i : mp)
//         {
//             for(int j = 0; j < i.second.size(); j++)
//             {
//                 v.push_back(i.second[j]);
//                 if(v.size() == i.first)
//                 {
//                     ans.push_back(v);
//                     v.clear();
//                 }
//             }
//         }
//         return ans;
//     }
// };