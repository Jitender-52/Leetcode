class Solution {
public:
    
//     Runtime: 31 ms, faster than 15.74% of C++ online submissions for Largest Positive Integer That Exists With Its Negative.
// Memory Usage: 26.6 MB, less than 15.10% of C++ online submissions for Largest Positive Integer That Exists With Its Negative.
    
    int findMaxK(vector<int>& v) {
    int n = v.size();
        map<int,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[v[i]]++;
        }
        
        int ans = -1;
        for(int i = 0; i < n; i++)
        {
            if(v[i] > 0 && mp[-v[i]] > 0)
            {
                ans = max(ans, v[i]);
            }
        }
        return ans;
    }
};