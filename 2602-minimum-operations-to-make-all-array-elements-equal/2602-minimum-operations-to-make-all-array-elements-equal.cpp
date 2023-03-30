class Solution {
public:
    
        vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            map<long long,pair<long long,long long>> mp1;
            long long sum = 0;
            mp1[0] = {0, 0};
            for(int i = 0; i < n; i++)
            {
                sum += nums[i];
                mp1[nums[i]] = {sum, i+1};
            }
            
            map<long long, pair<long long,long long>> mp2;
            mp2[INT_MAX] = {0, 0};
            sum = 0;
            int j = 1;
            for(int i = n-1; i >= 0; i--)
            {
                sum += nums[i];
                mp2[nums[i]] = {sum, j};
                j++;
            }
            
            vector<long long> v;
            for(auto x : queries)
            {
                auto l = mp1.lower_bound(x);
                l--;
                auto u = mp2.upper_bound(x);
                long long count = u->second.first - (u->second.second * x) + (x * l->second.second) - l->second.first; 
                // cout << l->second.first << " " << l->second.second << endl;
                // cout << u->second.first << " " << u->second.second << endl;
                v.push_back(count);
            }
            return v;
        }
};
    
    
    
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
        
//         long long sum = 0;
//         vector<long long> v(n);
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//             v[i] = sum;
//             mp[nums[i]] = i+1;
//         }
        
//         mp[-1] = 1;
//         int q = queries.size();
//         vector<long long> ans(q);
//         for(int i = 0; i < q; i++)
//         {
//             auto it = mp.lower_bound(queries[i]);
//             if(it->first == -1)
//             {
//                 // cout << i << endl;
//                 ans[i] = sum - n * queries[i];
//             }
//             else
//             {
//                 ans[i] = (it->second * v[it->second-1]) - queries[i] * it->second + queries[i] * (n-it->second) - (n - it->second) * (sum - v[it->second-1]); 
//             }
//         }
//         return ans;
//     }
// };