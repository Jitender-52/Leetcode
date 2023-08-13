class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    long long fast_power(long long x, long long p)
    {
        if (p == 0)
            return 1;

        long long ans = fast_power((x * x) % mod, p / 2) % mod;

        if (p & 1)
            ans *= x;
        return ans % mod;
    }

    
    int factorization(long long n)
    {
        vector<long long> v;
        for (long long d = 2; d * d <= n; d++)
        {
            while (n % d == 0)
            {
                v.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            v.push_back(n);
        set<long long> st;
        for(auto i : v)
        {
            st.insert(i);
        }
        int sz = st.size();
        return sz;
    }
    
    
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> factors(n);
        
        for(int i = 0; i < n; i++)
        {
            factors[i] = factorization(nums[i]);
        }
        
        stack<int> left, right;
        vector<int> pref(n, -1), suff(n, n);
        for(int i = 0; i < n; i++)
        {
            while(!left.empty() && factors[left.top()] < factors[i])
            {
                left.pop();
            }
            if(left.empty())
            {
                pref[i] = -1;
            }
            else
            {
                pref[i] = left.top();
            }
            left.push(i);
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            while(!right.empty() && factors[right.top()] <= factors[i])
            {
                right.pop();
            }
            if(right.empty())
            {
                suff[i] = n;
            }
            else
            {
                suff[i] = right.top();
            }
            right.push(i);
        }
        
        vector<pair<long long, long long>> v(n);
        
        for(int i = 0; i < n; i++)
        {
            v[i] = {nums[i], (i - pref[i]) * 1LL * (suff[i] - i)};
        }
        
        sort(v.rbegin(), v.rend());
        
        long long ans = 1;
        for(int i = 0; i < n && k > 0; i++)
        {
            long long x = min(1LL * k, v[i].second);
            (ans *= fast_power(v[i].first, x)) %= mod;
            k -= x;
        }
        return ans;
        
        
        
        // will not work in the case of repitions
        
        // map<long long, long long > mp;
        // for(int i = 0; i < n; i++)
        // {
        //     mp[nums[i]] = (i - pref[i]) * 1LL * (suff[i] - i);
        // }
                        
//         sort(nums.rbegin(), nums.rend());
        
//         long long ans = 1;
//         for(int i = 0; i < n && k > 0; i++)
//         {
//             long long x = min(1LL * k, mp[nums[i]]), a = 1LL * nums[i];
//             ans *= fast_power(a, x);
//             ans %= mod;
//             cout << a << " " << x << endl;
//             k -= x;
//         }
//         cout << endl;
//         return ans;
    }
};
    
    
//     int maximumScore(vector<int>& nums, int k) {
//         int n = nums.size();
//         map<int,int> mp1, mp2, mp3, mp4, mp;
//         mp1[1e6] = 0;
//         mp2[1e6] = n;
//         for(int i = 0; i < n; i++)
//         {
//             int x = factorization(nums[i]);
//             auto it = mp1.lower_bound(x);
//             if(nums[i] == 9)
//             {
//                 cout << it->first << " " << it->second << endl;
//                 cout << "check = " << i << " " << it->second << endl;
//             }
//             if(it->first == x)
//             {
//                 mp3[nums[i]] += i - it->second - 1;
//             }
//             else
//             {
//                 mp3[nums[i]] += i - it->second;
//             }
//             mp1[x] = i;
//         }
        
//         for(int i = n-1; i >= 0; i--)
//         {
//             int x = factorization(nums[i]);
//             auto it = mp2.upper_bound(x);
//             mp4[nums[i]] += it->second - i - 1;
//             mp2[x] = i;
//         }
//         sort(nums.rbegin(), nums.rend());
        
//         long long ans = 1;
//         for(int i = 0; i < n && k > 0; i++)
//         {
//             int a = mp[nums[i]] + 1;
//             cout << nums[i] << " " << mp3[nums[i]] << " " << mp4[nums[i]] << endl;
//             mp[nums[i]] = (mp3[nums[i]] + 1) * (mp4[nums[i]] + 1);
//             if(k >= mp[nums[i]])
//             {
//                 ans *= fast_power(1ll * nums[i], 1LL * mp[nums[i]]) % mod;
//                 cout << nums[i] << " " << mp[nums[i]] << endl;
//                 k -= mp[nums[i]];
//             }
//             else
//             {
//                 ans *= fast_power(1LL * nums[i], 1LL * k) % mod;
//                 cout << nums[i] << " " << k << endl;
//                 k = 0;
//             }
//             ans %= mod;
//         }
//         ans %= mod;
//         return ans;
//     }
// };

// 11 13 23
// 2 3 59
// 2 17 19 23
// 3 11 23 29
