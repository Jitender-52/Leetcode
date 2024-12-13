class Solution {
public:
    
//     Runtime: 64 ms, faster than 83.39% of C++ online submissions for Find Score of an Array After Marking All Elements.
// Memory Usage: 108.7 MB, less than 33.33% of C++ online submissions for Find Score of an Array After Marking All Elements.
    
    long long findScore(vector<int>& nums) {
        int n = nums.size();
//         map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[nums[i]]++;
//         }
        
//         for
        
        vector<int> vis(n+2, 0);
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }
        
        sort(v.begin(), v.end());
        long long ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[v[i].second])
            {
                ans += v[i].first;
                int x = v[i].second;
                if(x > 0)
                {
                    vis[x-1] = 1;
                }
                if(x < n-1)
                {
                    vis[x+1] = 1;
                }
            }
            vis[v[i].second] = 1;
        }
        return ans;
    }
};