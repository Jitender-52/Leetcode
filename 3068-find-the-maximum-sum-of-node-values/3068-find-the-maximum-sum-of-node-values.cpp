class Solution {
public:
    
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long n = nums.size();

        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            if ((nums[i] ^ k) > nums[i])
            {
                v.push_back(i);
            }
        }

        long long m = v.size();
        long long ans = 0;

        for (auto i : nums)
        {
            ans += i;
        }

        if (m % 2 == 0)
        {
            ans = 0;
            for (auto i : nums)
            {
                ans += 1LL * max(i, (i ^ k));
            }
            return ans;
        }
        else
        {
            long long ans2 = ans;
            for (long long i : v)
            {
                ans -= nums[i];
                long long x = 1LL * (nums[i]) ^ k;
                ans += x;
            }

            for (long long i = 0; i < m; i++)
            {
                long long x = 1LL * (nums[v[i]]) ^ k;
                long long sum = ans - x + nums[v[i]];
                ans2 = max(ans2, sum);
            }

            vector<long long> vis(n, 0);

            for (long long i = 0; i < m; i++)
            {
                vis[v[i]] = 1;
            }

            for (long long i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    long long x = 1LL * (nums[i]) ^ k;
                    long long sum = ans - nums[i] + x;
                    ans2 = max(ans2, sum);
                }
            }
            ans = ans2;
        }
        return ans;
    }
};
    
//     long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
//         int n = edges.size();
//         vector<vector<int>> adj(n);
//         for(auto i : edges)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             vector<int> v = adj[i];
//             v.push_back(i);
//             int m = v.size();
//             long long sum = 0;
//             for(int j = 0; j < m; j++)
//             {
//                 sum += 
//             }
//         }
        
// //         int n = nums.size();
// //         long long ans2 = 0;
// //         vector<long long> a(n), b(n);
// //         for(int i = 0; i < n; i++)
// //         {
// //             ans2 += 1LL * nums[i];
// //             a[i] = 1LL * (min(nums[i], nums[i] ^ k));
// //             b[i] = 1LL * (max(nums[i], nums[i] ^ k));
// //         }
        
// //         if(n % 2 == 1)
// //         {
// //             long long ans = 0;
// //             for(int i = 0; i < n; i++)
// //             {
// //                 ans += b[i];
// //             }
// //             return max(ans, ans2);
// //         }
        
// //         // int mini = 0;
// //         // for(int i = 0; i < n; i++)
// //         // {
// //         //     mini = min(mini, a[i]);
// //         // }
// //         long long sum = 0;
// //         for(int i = 0; i < n; i++)
// //         {
// //             sum += b[i];
// //         }
// //         for(int i = 0; i < n; i++)
// //         {
// //             ans = max(ans, sum - b[i] + a[i]);
// //         }
// //         return ans;
//     }
// };