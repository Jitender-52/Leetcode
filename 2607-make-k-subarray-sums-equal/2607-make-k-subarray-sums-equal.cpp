class Solution {
public:
    
    
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> vis(n+1, 0);
        long long ans = 0LL;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                int temp = i;
                vector<long long> v;
                while(vis[temp] == 0)
                {
                    vis[temp] = 1;
                    v.push_back(arr[temp]);
                    temp = (temp + k) % n; 
                }
                
                sort(v.begin(), v.end());
                long long m = v.size();
                long long median = v[m / 2];
                if(m % 2 == 0)
                {
                    median = (v[m/2] + v[m/2 - 1]) / 2;
                }
                for(auto j : v)
                {
                    ans += abs(j - median);
                }
            }
        }
        return ans;
    }
};
            
            
            
    
//     vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
//             int n = nums.size();
//             sort(nums.begin(), nums.end());
//             map<long long,pair<long long,long long>> mp1;
//             long long sum = 0;
//             mp1[0] = {0, 0};
//             for(int i = 0; i < n; i++)
//             {
//                 sum += nums[i];
//                 mp1[nums[i]] = {sum, i+1};
//             }
            
//             map<long long, pair<long long,long long>> mp2;
//             mp2[INT_MAX] = {0, 0};
//             sum = 0;
//             int j = 1;
//             for(int i = n-1; i >= 0; i--)
//             {
//                 sum += nums[i];
//                 mp2[nums[i]] = {sum, j};
//                 j++;
//             }
            
//             vector<long long> v;
//             for(auto x : queries)
//             {
//                 auto l = mp1.lower_bound(x);
//                 l--;
//                 auto u = mp2.upper_bound(x);
//                 long long count = u->second.first - (u->second.second * x) + (x * l->second.second) - l->second.first; 
//                 // cout << l->second.first << " " << l->second.second << endl;
//                 // cout << u->second.first << " " << u->second.second << endl;
//                 v.push_back(count);
//             }
//             return v;
//         }
    
//     long long minOp (vector<long long> arr, int n)
// {
        
// //         long long int n = arr.size();
        
// //         map<long long int,long long int> mp;
// //         for(auto it : arr) mp[it]++;
        
// //         long long int maxi = 0;
// //         for(auto it : mp) maxi = max(maxi,it.second);
// //         long long int val;
// //         for(auto it : mp) if(it.second == maxi){
// //             val = it.first;
// //         }
        
// //         long long int ans =0 ;
// //         for(int i = 0; i< n ; i++){            
// //             ans += abs(arr[i]-val);            
// //         }
        
// //         return ans;
//     int sum = accumulate(arr.begin(), arr.end() ,0);
//     int small = *min_element(arr.begin(), arr.end());
//     int minOperation = sum - (n * small);
//     return minOperation;
// }
    
//     long long makeSubKSumEqual(vector<int>& arr, int k) {
//         int n = arr.size();
//         vector<long long> v;
//         long long sum = 0;
//         for(int i = 0; i < k; i++)
//         {
//             sum += arr[i];
//         }
        
//         int j = 0;
//         v.push_back(sum);
//                 vector<long long> v1;
//         for(int i = 0; i < n; i++)
//         {
//             // cout << i << endl;
//             sum += arr[(i+k) % n];
//             sum -= arr[i];
//             if(i < n-1)
//             v.push_back(sum);
//             v1.push_back(arr[i]);
//         }
        
//         // return minOperations(nums);
        
//         // return minOp(v, n);
        
//         for(int i = 0; i < v.size(); i++)
//         {
//             cout << v[i] <<" ";
//         }
//         cout << endl;
        
//                 return minOp(v, n);
        
        
//     }
// };