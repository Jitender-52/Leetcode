class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int b = 0, ans = 0;
        for(auto i : nums)
        {
            b += i;
            if(b == 0)
                ans++;
        }
        return ans;
    }
};