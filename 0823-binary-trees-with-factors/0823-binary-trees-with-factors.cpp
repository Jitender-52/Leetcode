class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int trees(int root, vector<int> &arr, map<int,int> &mp)
    {
        int n = arr.size();
        long long ans = 1;
        for(int i = 0; i < n && arr[i] * 1LL * arr[i] <= root; i++)
        {
            if(root % arr[i] == 0)
            {
                if(root / arr[i] == arr[i])
                {
                    (ans += 1LL * mp[arr[i]] * mp[arr[i]]) %= mod;
                }
                else
                {
                    (ans += 2LL * mp[arr[i]] * mp[root / arr[i]]) %= mod;
                }
            }
        }
        return ans;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a = trees(arr[i], arr, mp);
            (ans += a) %= mod;
            mp[arr[i]] = a;
        }
        return ans;
    }
};


// const int mod = 1e9 + 7;
    
// //  **********************************************************   DP Recursive Method  O(N ^ 2) && O(N) **********************************************************
    
//     long long binaryTrees(int root, vector<int> &arr, map<int, int> &mp)
//     {
//         int n = arr.size();
        
//         long long count = 1;
        
//         for(int i = 0; arr[i] <= sqrt(root)  && i < n; i++)
//         {
//             if(root % arr[i] == 0 && mp[root / arr[i]] >= 1)
//             {
//                 if(arr[i] == root / arr[i])
//                 {
//                     count += (long)mp[arr[i]] * mp[arr[i]];
//                     count = count % mod;
//                 }
//                 else
//                 {
                    
//                 count += (long)2 * mp[arr[i]] * mp[root / arr[i]];

//                     count = count % mod;
//                 }
//             }
          
//         }
//         return (int)count % mod;
//     }
    
//         int numFactoredBinaryTrees(vector<int>& arr) {
//             int n = arr.size();
//             sort(arr.begin(), arr.end());
            
//             map<int, int> mp;
//             for(int i = 0; i < n; i++)
//             {
//                 mp[arr[i]]++;
//             }
            
//             // map<int, int> v;
            
//             // vector<int> v(arr[n-1] + 1, -1);
//             long long ans = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 long long a = binaryTrees(arr[i], arr, mp) % mod;
//                 a = a % mod;
//                 mp[arr[i]] = a;
//                 ans += a;
//                 ans = ans % mod;
//             }
//             return (int)ans % mod;
//         }
// };




//  ***********************************************   DP Recursive Method   O(N^2) && O(2 * N) ***********************************************
    
//     long long binaryTrees(int root, vector<int> &arr, map<int, int> &mp, map<int, int> &v)
//     {
//         int n = arr.size();
        
//         long long count = 1;
        
//         for(int i = 0; arr[i] <= sqrt(root)  && i < n; i++)
//         {
//             if(root % arr[i] == 0 && mp[root / arr[i]] == 1)
//             {
//                 if(arr[i] == root / arr[i])
//                 {
//                     count += (long)v[arr[i]] * v[arr[i]];
//                     count = count % mod;
//                 }
//                 else
//                 {
                    
//                 count += (long)2 * v[arr[i]] * v[root / arr[i]];

//                     count = count % mod;
//                 }
//             }
          
//         }
//         return (int)count % mod;
//     }
    
//         int numFactoredBinaryTrees(vector<int>& arr) {
//             int n = arr.size();
//             sort(arr.begin(), arr.end());
            
//             map<int, int> mp;
//             for(int i = 0; i < n; i++)
//             {
//                 mp[arr[i]]++;
//             }
            
//             map<int, int> v;
            
//             // vector<int> v(arr[n-1] + 1, -1);
//             long long ans = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 long long a = binaryTrees(arr[i], arr, mp, v) % mod;
//                 a = a % mod;
//                 v[arr[i]] = a;
//                 ans += a;
//                 ans = ans % mod;
//             }
//             return (int)ans % mod;
//         }
// };




// ERRORS IN UPPER APPROACH

 // count += (2 * (v[root / arr[i]]) * (v[arr[i]])) % mod;
                    // long long a = (v[root / arr[i]] * v[arr[i]]) % mod;
                    // a = a % mod;
                    // a = (a * 2) % mod;
                    // // count += a;
                      // count += 2 *(binaryTrees(root / arr[i], arr, mp, v) * binaryTrees(arr[i], arr, mp, v));



      // if(root % arr[i] == 0 && mp[root / arr[i]] == 1)
            // {
            //     if(arr[i] == root / arr[i])
            //     {
            //          count += v[arr[i]] * v[arr[i]];
            //         count = count % mod;
            //     }
            //     else
            //     {
            //         count += 2 * v[root / arr[i]] * v[arr[i]];
            //         count = count % mod;
            //     }
            // }
    
    
    
    
    
   //   **********************************************    Recursive Brute Force Approach    *********************************************
    
//     long long binaryTrees(int root, vector<int> &arr, map<int, int> &mp)
//     {
//         int n = arr.size();
//         int i = 0;
//         long long count = 1;
//         while(arr[i] <= sqrt(root) && i < n)
//         {
//             if(root % arr[i] == 0 && mp[root / arr[i]] == 1)
//             {
//                 if(arr[i] == root / arr[i])
//                 {
//                      count += pow(binaryTrees(arr[i], arr, mp), 2);
//                     count = count % mod;
//                 }
//                 else
//                 {
//                     count += 2 *(binaryTrees(root / arr[i], arr, mp) * binaryTrees(arr[i], arr, mp));
//                     count = count % mod;
//                 }
//             }
//             i++;
//         }
//         return count % mod;
//     }
    
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
        
//         map<int, int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[arr[i]]++;
//         }
        
//         long long ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             ans += binaryTrees(arr[i], arr, mp);
//             ans = ans % mod;
//         }
//        return (int)(ans % mod);
//     }
    
    
    
// };



// TESTCASES

// [2,4]
// [2,4,5,10]
// [2]
// [18,3,6,2]
// [18,36,3,6,2]
// [45,42,2,18,23,1170,12,41,40,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,31,14,19,8,13,7,27,22,3,34,38,39,30,43,15,35,20,44,5,48]
    



//      VOID METHOD (NOT ACCEPTED)
    
//     void binaryTrees(int root, vector<int> &arr, map<int, int> &mp, int &ans, int count)
//     {
//         ans += count;
//         int i = 0;
//        while(arr[i] <= sqrt(root))
//        {
//             if(root % arr[i] == 0 && mp[root / arr[i]] == 1)
//             {
//                 if(arr[i] == root / arr[i])
//                 {
//                 // binaryTrees(arr[i], arr, mp, ans, 2 *  count);
//                    binaryTrees(arr[i], arr, mp, ans, count * 2);
//                    binaryTrees(arr[i], arr, mp, ans, count * 2);
//                 }
//                 else
//                 {
//                 binaryTrees(arr[i], arr, mp, ans, count * 2);
//                 binaryTrees(root / arr[i], arr, mp, ans, count * 2);
//                 }
//             }
//            i++;
//         }
//         return;
//     }
    
//     int numFactoredBinaryTrees(vector<int>& arr) {
//         int n = arr.size();
//         sort(arr.begin(), arr.end());
        
//         map<int, int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[arr[i]]++;
//         }
        
//         int ans = 0;
//         int count = 1;
//         for(int i = 0; i < n; i++)
//         {
//             // cout << i << endl;
//             ans++;
//             binaryTrees(arr[i], arr, mp, ans, count);
//         }
//         return ans/2;
//     }
// };
