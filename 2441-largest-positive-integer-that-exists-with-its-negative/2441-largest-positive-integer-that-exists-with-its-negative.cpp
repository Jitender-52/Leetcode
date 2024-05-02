class Solution {
public:
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