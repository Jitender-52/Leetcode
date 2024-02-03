class Solution {
public:
    
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<int> v(n, 0);
//         map<int,int> mp;
//         for(int i = 0; i < k; i++)
//             mp[arr[i]]++;
//         for(int i = 0; i < n; i++)
//         {
//             v[i] = (*mp.rbegin()).first;
//             if(i - k >= 0)
//             {
//                 mp[arr[i-k]]--;
//                 if(mp[arr[i-k]] == 0)
//                     mp.erase(arr[i-k]);
//             }
//             if(i + k < n)
//             {
//                 mp[arr[i+k]]++;
//             }
//         }
//         int sum = 0;
//         for(int i = 0; i < n; i++)
//             sum += v[i];
//         for(int i = 0; i < n; i++)
//             cout << v[i] << " ";
//         return max(sum-v[0], sum-v[n-1]);
//     }
// };
    
//     Runtime: 11 ms, faster than 74.73% of C++ online submissions for Partition Array for Maximum Sum.
// Memory Usage: 10.7 MB, less than 28.35% of C++ online submissions for Partition Array for Maximum Sum.
    
    int maxSum(vector<int>& arr, int k, int dp[], int start) {
        int N = arr.size();
        
        if (start >= N) {
            return 0;
        }
        if (dp[start] != -1) {
            return dp[start];
        }
        int currMax = 0, ans = 0;
        int end = min(N, start + k);
        for (int i = start; i < end; i++) {
            currMax = max(currMax, arr[i]);
            ans = max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }
        return dp[start] = ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int dp[arr.size()];
        memset(dp, -1, sizeof(dp));
        
        return maxSum(arr, k, dp, 0);
    }
};
    
//     int maxSumAfterPartitioning(vector<int>& arr, int k) {
//         int n = arr.size();
//         map<int,int> mp;
//         for(int i = 0; i < k; i++)
//         {
//             mp[arr[i]]++;
//         }
        
//         int j = 0;
//         for(int i = k; i < n; i++)
//         {
//             int a = arr[j];
//             arr[j] = mp.rbegin()->first;
//             mp[arr[i]]++;
//             mp[a]--;
//             if(mp[a] == 0)
//                 mp.erase(a);
//             cout << j + k << endl;
//             if(j + k < n)
//                 mp[arr[j+k]]++;
//             j++;
//         }
        
//         int sum = 0;
//         for(int i = 0; i < n; i++)
//         {
//             cout << arr[i] << " ";
//             sum += arr[i];
//         }
//         return max(sum - arr[0], sum - arr[n-1]);
//     }
// };