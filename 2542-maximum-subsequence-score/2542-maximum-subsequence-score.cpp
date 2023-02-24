class Solution {
public:
    
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            int n = nums1.size();
            vector<pair<int,int>> v;
            for(int i = 0; i < n; i++)
            {
                v.push_back({nums2[i], nums1[i]});
            }
            
            sort(v.rbegin(), v.rend());
            
            long long sum = 0;
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int i = 0; i < k; i++)
            {
                sum += v[i].second;
                pq.push(v[i].second);
            }
            
            long long ans = sum * v[k-1].first;
            for(int i = k; i < n; i++)
            {
                sum -= pq.top();
                pq.pop();
                sum += v[i].second;
                pq.push(v[i].second);
                ans = max(ans, sum * v[i].first);
            }
            return ans;
        }
};
    
    
    
    
//     Runtime: 273 ms, faster than 82.89% of C++ online submissions for Maximum Subsequence Score.
// Memory Usage: 92 MB, less than 48.24% of C++ online submissions for Maximum Subsequence Score.
// Next challenges:
    
    
//         long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//             int n = nums1.size();
//             vector<pair<int,int>> v;
//             for(int i = 0; i < n; i++)
//             {
//                 v.push_back({nums2[i], nums1[i]});
//             }
            
//             sort(v.rbegin(), v.rend());
            
//             long long sum = 0;
//             int mini = INT_MAX;
//             priority_queue<int, vector<int>, greater<int>> pq;
//             for(int i = 0; i < k; i++)
//             {
//                 sum += v[i].second;
//                 pq.push(v[i].second);
//                 mini = min(mini, v[i].first);
//             }
            
//             long long ans = sum * mini;
//             for(int i = k; i < n; i++)
//             {
//                 sum -= pq.top();
//                 pq.pop();
//                 sum += v[i].second;
//                 mini = min(mini, v[i].first);
//                 pq.push(v[i].second);
//                 ans = max(ans, sum * mini);
//             }
//             return ans;
//         }
// };
    
    
    
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size();
        
//         vector<pair<int,int>> v;
        
//         long long ans = 0;
//         long long sum = 0;
        
//         for(int i = 0; i < n; i++)
//         {
//             v.push_back({nums1[i], i});
//         }
        
//         vector<bool> vis(n, 0);
        
//         sort(v.rbegin(), v.rend());
        
//         int mini = INT_MAX;
//         for(int i = 0; i < k-1; i++)
//         {
//             sum += v[i].first;
//             mini = min(mini, nums2[v[i].second]);
//             vis[v[i].second] = 1;
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             if(vis[i] == 1)
//             {
//                 vis[i] = 0;
//                 continue;
//             }
//             ans = max(ans, (sum + nums1[i]) * min(mini, nums2[i]));
//         }
        
        
//         // vis(n, 0);
        
//         sum = 0;
        
//         sort(v.begin(), v.end());
        
//         mini = INT_MAX;
//         for(int i = 0; i < k-1; i++)
//         {
//             sum += v[i].first;
//             mini = min(mini, nums2[v[i].second]);
//             vis[v[i].second] = 1;
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             if(vis[i] == 1)
//                 continue;
//             ans = max(ans, (sum + nums1[i]) * min(mini, nums2[i]));
//         }
        
//         return ans;
        
// //         map<int,int> mp;

// //         for(int i = 0; i < k; i++)
// //         {
// //             sum += nums1[i];
// //             mp[nums2[i]]++;
// //         }
        
// //         ans = sum * mp.begin()->first;
// //         cout << ans << endl;
// //         for(int i = k; i < n; i++)
// //         {
// //             cout << i << " " << i-k << endl;
// //             sum += nums1[i];
// //             sum -= nums1[i-k];
// //             mp[nums2[i]]++;
// //             mp[nums2[i-k]]--;
// //             if(mp[nums2[i-k]] == 0)
// //                 mp.erase(nums1[i-k]);
// //             ans = max(ans, sum * mp.begin()->first);
// //         }
// //         return ans;        
//     }
// };

// [2,1,14,12]
// [11,7,13,6]
// 3