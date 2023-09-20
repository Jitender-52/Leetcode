class Solution {
public:
    
//     Runtime: 126 ms, faster than 58.88% of C++ online submissions for Minimum Operations to Reduce X to Zero.
// Memory Usage: 98.9 MB, less than 35.28% of C++ online submissions for Minimum Operations to Reduce X to Zero.
    
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        int a = sum - x;
        if(a < 0)
            return -1;
        int ans = 1e9;
        int i = 0, j = 0;
        // cout << a << endl;
        while(j < n)
        {
            // if(a == 0)
            //     ans = min(ans, (i - j + 1));
            if(i < n && a >= 0)
            {
                a -= nums[i];
                i++;
            }
            else
            {
                a += nums[j];
                j++;
            }
            // cout << a << " ";
            if(a == 0)
            {
                // cout << i << " " << j << endl;
                ans = min(ans, n - (i - j));
            }
        }
        // cout << endl;
        return ans == 1e9 ? -1 : ans;
    }
};