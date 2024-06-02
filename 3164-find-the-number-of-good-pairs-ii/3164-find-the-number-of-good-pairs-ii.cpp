class Solution {
public:

    vector<long long> factors(long long n)
    {
        vector<long long> ans;
        long long a = 1, b = n;
        while (a <= sqrt(n))
        {
            if (a > b)
            {
                break;
            }
            if (n % a == 0)
            {
                ans.push_back(a);
                b = n / a;
                if(a != b)
                    ans.push_back(b);
            }
            a++;
        }
        return ans;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        long long ans = 0;
        vector<long long> count(1e6+1, 0);
        for(auto i : nums2)
            count[i]++;
        
        for(int i = 0; i < n; i++)
        {
            if(nums1[i] % k == 0)
            {
                nums1[i] /= k;
                vector<long long> v = factors(nums1[i]);
                for(auto j : v)
                {
                    ans += count[j];
                }
            }
        }
        return ans;
    }
};