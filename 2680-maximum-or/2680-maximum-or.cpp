class Solution {
public:
    
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);
        vector<long long> suff(n+1, 0);
        
        int a = 0;
        for(int i = 0; i < n; i++)
        {
            pref[i] = a;
            a |= nums[i];
        }
        a = 0;
        for(int i = n-1; i >= 0; i--)
        {
            suff[i] = a;
            a |= nums[i];
        }
        
        a = 1;
        for(int i = 0; i < k; i++)
        {
            a *= 2;
        }
        
        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            long long x = 0;
            x = suff[i] | pref[i] | (nums[i] * 1LL * a);
            ans = max(ans, x);
        }
        return ans;
    }
};
    
    
//     long long maximumOr(vector<int>& nums, int k) {
//         long long n = nums.size();
     
        
//         map<int,int> mp;
        
        
//         int b= 1;
//         for(int i = 0; i < k; i++)
//         {
//             b *= 2;
//         }
        
//         for(int i = 0; i < 20; i++)
//         {
//             mp[i] = 0;
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             int a= 1;
//             int count = 0;
//             while(a <= nums[i])
//             {
//                 a *= 2;
//                 count++;
//             }
//             a /= 2;
//             count--;
            
//             int x = nums[i];
//             while(x != 0)
//             {
//                 mp[count] += x / a;
//                 x -= (x/a) * a;
//                 a /= 2;
//             }
//         }
        
        
//         int ans= 0;
//         for(int i = 0; i < n; i++)
//         {
//             int a= 1;
//             int count = 0;
//             while(a <= nums[i])
//             {
//                 a *= 2;
//                 count++;
//             }
//             a /= 2;
//             count--;
            
//             int x = nums[i];
//             while(x != 0)
//             {
//                 mp[count] -= x / a;
//                 x -= (x/a) * a;
//                 a /= 2;
//             }
            
//             nums[i] *= b;
            
//             a = 1;
//             count = 0;
//             while(a <= nums[i])
//             {
//                 a *= 2;
//                 count++;
//             }
//             a /= 2;
//             count--;
            
//             x = nums[i];
//             while(x != 0)
//             {
//                 mp[count] -= x / a;
//                 x -= (x/a) * a;
//                 a /= 2;
//             }
            
//             int num = 0;
//             a = 1;
//             // cout << mp.size() << endl;
//             // return 0;
//             for(auto i : mp)
//             {
//                 if(i.second > 0)
//                 {
//                     num += a;
//                 }
//                 a *= 2;
//             }
//             ans = max(ans, num);   
//         }
        
//         return ans;
        
// //         long long ans = 0;
// //         int maxi = 0;
// //         for(long long i = 0; i < n; i++)
// //         {
// //             maxi = max(maxi, nums[i]);
// //         }
        
// //         long long a = 1;
// //         while(a <= maxi)
// //         {
// //             a *= 2;
// //         }
// //         a /= 2;
        
// //         int mini = INT_MAX;
        
// //         for(long long i = 0; i < n; i++)
// //         {
// //             if(nums[i] >= a)
// //             {
// //                 mini = min(mini, nums[i]);
// //             }
// //         }
        
// //         long long b = 1;
// //         for(long long i = 0; i < k; i++)
// //         {
// //             b *= 2;
// //         }
        
// //         for(long long i = 0; i < n; i++)
// //         {
// //             if(nums[i] == mini)
// //             {
// //                 nums[i] *= b;
// //                 break;
// //             }
// //         }
        
// //         for(long long i = 0; i < n; i++)
// //         {
// //             ans = ans | nums[i];
// //         }
        
// //         return ans;
        
// //         long long a = 1;
// //         for(long long i = 0; i < k; i++)
// //         {
// //             a *= 2;
// //         }
        
// //         for(long long i = 0; i < n; i++)
// //         {
// //             if(nums[i] == maxi)
// //             {
// //                 nums[i] *= a;
// //                 break;
// //             }
// //         }
        
// //         // long long ans = 0;
        
// //         for(long long i = 0; i < n;i++)
// //         {
// //             cout << nums[i] <<" ";
// //             ans = ans | nums[i];
// //         }
// //         cout << endl;
        
// //         return ans;
        
        
        
// // //         long long sum = 1;
// // //         for(auto &i : nums)
// // //         {
// // //             sum *= i;
// // //         }
        
// // //         for(long long i = 0; i < n; i++)
// // //         {
            
// // //         }
        
//     }
// };