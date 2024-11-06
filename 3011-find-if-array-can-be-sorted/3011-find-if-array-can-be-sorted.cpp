class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v;
        for(auto i : nums)
        {
            int count = 0;
            for(int j = 0; j < 10; j++)
                count += ((i & (1 << j)) != 0);
            v.push_back({i, count});
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j > 0; j--)
            {
                // cout << v[j].first << v[j].second << " " << 
                if(v[j].first < v[j-1].first)
                {
                    if(v[j].second != v[j-1].second)
                        return false;
                    else
                        swap(v[j], v[j-1]);
                }
            }
        }
        
        return true;
        
        // for(int i = n-1; i < n; i++)
        // {
        //     for(int j = i+1; j < n; j++)
        //     {
        //         if(nums[])
        //     }
        // }
        
    }
};