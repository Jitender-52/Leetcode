class Solution {
public:
    
        vector<int> topKFrequent(vector<int>& nums, int k) {
            map<int,int> mp;
            for(auto &i : nums)
                mp[i]++;
            priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
            for(auto &i : mp)
                pq.push({i.second, i.first});
            vector<int> ans;
            for(int i = 0; i < k; i++)
            {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            return ans;
        }
};
    
//     Runtime: 23 ms, faster than 25.25% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.8 MB, less than 42.78% of C++ online submissions for Top K Frequent Elements.

    
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         map<int,int> mp;
//         for(auto &i : nums)
//             mp[i]++;
//         vector<pair<int,int>> v;
//         for(auto &i : mp)
//             v.push_back({i.second, i.first});
//         sort(v.rbegin(), v.rend());
//         vector<int> ans;
//         for(int i = 0; i < k; i++)
//             ans.push_back(v[i].second);
//         return ans;
//     }
// };