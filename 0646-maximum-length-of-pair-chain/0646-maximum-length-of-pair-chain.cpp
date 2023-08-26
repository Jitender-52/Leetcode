class Solution {
public:
    
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b)            {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int last = INT_MAX, ans = 0;    
        for(int i = n-1; i >= 0; i--)
        {
            if(pairs[i][1] < last)
            {
                ans++;
                last = pairs[i][0];
            }
        }
        return ans;
    }
};
    
    
//     Runtime: 53 ms, faster than 91.50% of C++ online submissions for Maximum Length of Pair Chain.
// Memory Usage: 22.5 MB, less than 86.44% of C++ online submissions for Maximum Length of Pair Chain.
    
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(), pairs.end(), [&](vector<int> &a, vector<int> &b)            {
//             if(a[1] == b[1])
//                 return a[0] < b[0];
//             return a[1] < b[1];
//         });
        
//         int last = INT_MIN, ans = 0;
//         for(auto &v : pairs)
//         {
//             if(v[0] > last)
//             {
//                 ans++;
//                 last = v[1];
//             }
//         }
//         return ans;
//     }
// };
    
    
    
//     Runtime: 232 ms, faster than 51.36% of C++ online submissions for Maximum Length of Pair Chain.
// Memory Usage: 22.8 MB, less than 69.55% of C++ online submissions for Maximum Length of Pair Chain.
    
//     int longest(int i, vector<vector<int>> &pairs, vector<int> &dp)
//     {
//         int n = pairs.size();
//         if(i >= n)
//             return 0;
//         if(dp[i] != -1)
//             return dp[i];
//         dp[i] = 1;
//         for(int j = i+1; j < n; j++)
//         {
//             if(pairs[j][0] > pairs[i][1])
//                 dp[i] = max(dp[i], 1 + longest(j, pairs, dp));
//         }
//         return dp[i];
//     }
    
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();
//         sort(pairs.begin(), pairs.end());
//         int ans = 0;
//         vector<int> dp(n, -1);
//         for(int i = 0; i < n; i++)
//         {
//             ans = max(ans, longest(i, pairs, dp));
//         }
//         return ans;
//     }
// };
    
    
//     Runtime: 205 ms, faster than 56.32% of C++ online submissions for Maximum Length of Pair Chain.
// Memory Usage: 22.8 MB, less than 55.03% of C++ online submissions for Maximum Length of Pair Chain.

    
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n = pairs.size();
//         sort(pairs.begin(), pairs.end());
//         vector<int> dp(n, 1);
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             for(int last = 0; last < i; last++)
//             {
//                 if(pairs[i][0] > pairs[last][1])
//                     dp[i] = max(dp[i], dp[last] + 1);
//             }
//             ans = max(ans, dp[i]);
//         }
//         return ans;
//     }
// };