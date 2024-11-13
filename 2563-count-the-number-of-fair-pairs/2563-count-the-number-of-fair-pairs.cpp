class Solution{
public:
    
//     Runtime: 70 ms, faster than 33.33% of C++ online submissions for Count the Number of Fair Pairs.
// Memory Usage: 61.2 MB, less than 5.96% of C++ online submissions for Count the Number of Fair Pairs.
    
    long long countPairSum(long long v[], long long lower, long long upper, long long n)
    {
        sort(v, v + n);
        long long right = n - 1, count = 0;
        while (right > 0)
        {
            auto it1 = lower_bound(v, v + n, lower - v[right]);
            long long left = it1 - v;
            auto it2 = upper_bound(v, v + n, upper - v[right]);
            --it2;
            long long end = it2 - v;
            end = min(end, right - 1);
            if (end - left >= 0)
            {
                count += (end - left + 1);
            }
            right--;
        }

        return count;
    }

    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long n = nums.size();
        long long v[n];
        for (long long i = 0; i < n; i++)
        {
            v[i] = nums[i];
        }
        return countPairSum(v, lower, upper, n);

        //         long long i = 0;
        //         long long j = i+1;

        //         sort(nums.begin(), nums.end());

        //         while(i < n)
        //         {
        //             long long sum = nums[i] + nums[j];
        //             if(sum <= lower)
        //             {
        //                 i++;
        //             }
        //             else if(sum >= upper)
        //             {

        //             }
        //         }

        long long ans = 0;
        map<long long, long long> mp;
        long long count = 0;
        mp[INT_MIN] = 0;
        sort(nums.begin(), nums.end());
        for (long long i = 0; i < n; i++)
        {
            count++;
            mp[nums[i]] = count;
        }
        mp[INT_MAX] = count;

        for (long long i = 0; i < n; i++)
        {
            long long a = lower - nums[i];
            long long b = upper - nums[i];
            ans += mp.lower_bound(b + 1)->second - mp.lower_bound(a - 1)->second;

            if (nums[i] >= a && nums[i] <= b)
            {
                ans--;
            }
        }
        return ans;
    }
};