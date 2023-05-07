class Solution {
public:
    
        vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
            int n = obstacles.size();
            vector<int> ans(n, 1), v;
            for(int i = 0; i < n; i++)
            {
                int idx = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin();
                if(idx == v.size())
                    v.push_back(obstacles[i]);
                else
                    v[idx] = obstacles[i];
                ans[i] = idx + 1;
            }
            return ans;
        }
};
    
    
//     vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
//         int n = obstacles.size();
//         map<int,int> mp;
//         mp[0] = 0;
//         mp[INT_MAX] = 0;
//         vector<int> ans(n);
//         for(int i = 0; i < n; i++)
//         {
//             auto it = mp.upper_bound(obstacles[i]);
//             it--;
//             mp[obstacles[i]] = it->second + 1;
//             ans[i] = mp[obstacles[i]];
//         }
//         return ans;
//     }
// };