class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> v;
        int f = 1;
        for(int i = 1; i < n; i++)
        {
            f *= i;
            v.push_back(i);
        }
        v.push_back(n);
        
        k--;
        string ans = "";
        for(int i = n-1; i >= 0; i--)
        {
            int a = k / f;
            k %= f;
            ans += (v[a] + '0');
        
            v.erase(v.begin() + a);
            
            if(i == 0)
                break;
            f /= i;
        }
        return ans;
    }
};
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
// Memory Usage: 6.2 MB, less than 7.24% of C++ online submissions for Permutation Sequence.
    
//         string getPermutation(int n, int k) {
//             vector<int> v;
//             vector<int> fac(n+1, 1);
//             int a = 1;
//             for(int i = 1; i <= n; i++)
//             {
//                 v.push_back(i);
//                 fac[i] = fac[i-1] * i; 
//             }
//             fac[0] = 1;
            
//             string ans = "";
//             k--; // because of 0  indexing
//             for(int i = n; i > 0; i--)
//             {
//                 a = k / fac[i-1];
//                 k %= fac[i-1];
//                 ans += (v[a] + '0');
//                 v.erase(v.begin() + a);
//                 // remove(v.begin(), v.end(), v.begin() + a);
//                 // v.erase(v.begin(), v.end(), v.begin() + a);
//             }
//             return ans;
//         }
// };
    
    
//         void permutation(int j, int num, int n, vector<int> &vis, vector<int> &ans)
//         {
//             if(j == n)
//                 ans.push_back(num);
//             for(int i = 1; i <= n; i++)
//             {
//                 if(!vis[i])
//                 {
//                     vis[i] = 1;
//                     int x = num * 10 + i;
//                     permutation(j+1, x, n, vis, ans);
//                     vis[i] = 0;
//                 }
//             }
//         }
    
//         string getPermutation(int n, int k) {
//             vector<int> ans;
//             vector<int> vis(10, 0);
//             permutation(0, 0, n, vis, ans);
//             sort(ans.begin(), ans.end());
//             int x = ans[k - 1];
//             string s = to_string(x);
//             return s;
//         }
// };
    
//     int factorial(int n, vector<int> &dp)
//     {
//         if(n == 1 || n == 0)
//             return 1;
//         if(dp[n] != 1)
//             return dp[n];
//         return dp[n] = n * factorial(n-1, dp);
//     }
    
//     string getPermutation(int n, int k) {
//         vector<int> dp(10, 1);
//         for(int i = 0; i < 10; i++)
//         {
//             factorial(i, dp);
//             // cout << dp[i] << endl;
//         }
        
//         string s = "";
//         for(int i = 1; i <= n; i++)
//         {
//             s += to_string(i);
//         }
        
//         for(int i = 9; i >= 0; i--)
//         {
            
//             if(dp[i] <= k)
//             {
//                 // cout << dp[i] << " " << k << endl;
//                 // reverse(s.begin(), s.begin()+i);
//                 reverse(s.begin()+i, s.end());
//                 // cout << i << " " << s << endl;
//                 k = k % dp[i];
//             }
//         }
//         // 321
//         // 312
        
//         return s;
//     }
// };

// 3
// 123


