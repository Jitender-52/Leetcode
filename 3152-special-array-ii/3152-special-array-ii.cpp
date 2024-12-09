class Solution {
public:
    
//     Runtime: 83 ms, faster than 10.16% of C++ online submissions for Special Array II.
// Memory Usage: 140.6 MB, less than 5.15% of C++ online submissions for Special Array II.
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        set<int> l, r;
        l.insert(-1);
        l.insert(n+2);
        r.insert(n+2);
        
        for(int i = 1; i < n; i++)
        {
            if(nums[i] % 2 == nums[i-1] % 2)
            {
                l.insert(i-1);
                // r.insert(i);
            }
        }
        
        vector<bool> ans(queries.size());
        int count = 0;
        for(auto v : queries)
        {
            int x = v[0], y = v[1];
            auto it = *l.lower_bound(x);
            if(x == y)
            {
                ans[count++] = 1;
                continue;
            }
            if(it == x)
            {
                if(nums[x] % 2 == nums[x+1] % 2)
                    ans[count++] = 0;
                else
                    ans[count++] = 1;
            }
            else if(it == y)
            {
                if(nums[y] % 2 == nums[y-1] % 2)
                    ans[count++] = 0;
                else
                    ans[count++] = 1;
            }
            else if(it >= x && it <= y)
            {
                // cout << it << endl;
                ans[count++] = 0;
            }
            else
            {
                ans[count++] = 1;
            }
        }
        return ans;
    }
};