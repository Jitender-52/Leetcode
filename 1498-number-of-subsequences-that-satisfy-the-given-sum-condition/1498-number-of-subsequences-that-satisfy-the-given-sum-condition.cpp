class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        
        int j = 0;
        
        int N = 1e5 + 1;
        vector<int> p(N, 0);
        long long a = 1;
        for(int i = 0; i < N; i++)
        {
            p[i] = a;
            (a *= 2) %= mod;
        }
        
        
        for(int i = 0; i < n; i++)
        {
            int x = target - nums[i];
            int low = i;
            int high = n-1;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(nums[mid] <= x)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            if(low - 1 < i)
                break;
            int y = (low-1) - i; // low-1 for finding the correct index
            (ans += p[y]) %= mod;
        }
        return ans;
        
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]] = i;
//         }
        
//         long long ans = 0;
//         mp[INT_MAX] = n;
//         for(int i = 0; i < 1; i++)
//         {
//             auto it = mp.upper_bound(target - nums[i]);
//             it--;
//             if(nums[it->first] - nums[i] > target)
//                 break;
//             long long x = nums[it->first] - i;
//             (ans += pow(2, x)) %= mod;
//         }
//         return ans;
    }
};