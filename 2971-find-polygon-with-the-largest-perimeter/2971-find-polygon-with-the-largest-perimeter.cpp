class Solution {
public:
    
//     Runtime: 159 ms, faster than 33.33% of C++ online submissions for Find Polygon With the Largest Perimeter.
// Memory Usage: 79.1 MB, less than 66.67% of C++ online submissions for Find Polygon With the Largest Perimeter.
    
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = nums[0] + nums[1];
        long long ans = -1;
        for(int i = 2; i < n; i++)
        {
            if(sum > nums[i])
                ans = max(ans, sum + nums[i]);
            sum += nums[i];
            // cout << i << " " << sum << endl;
        }
        if(sum - nums[n-1] > nums[n-1])
            ans = max(ans, sum);
        return ans;
    }
};