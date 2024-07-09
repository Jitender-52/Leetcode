class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int smaller = -1e9, larger = 1e9;
        for(int i = 0; i < n-2; i++)
        {
            int l = i + 1, r = n - 1;
            while(l < r)
            {
                int a = nums[i] + nums[l] + nums[r];
                if(a == target)
                    return target;
                if(a < target)          
                {
                    smaller = max(smaller, a);
                    l++;
                }
                else
                {
                    larger = min(larger, a);
                    r--;
                }
            }
        }
        if(target - smaller < larger - target)
            return smaller;
        return larger;
    }
};