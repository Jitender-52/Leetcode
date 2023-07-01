class Solution {
public:
    
    int dfs(int i, vector<int> &cookies, vector<int> &v, int k)
    {
        int n = cookies.size();
        if(i == n)
        {
            return *max_element(v.begin(), v.end());
        }
        
        int ans = 1e9;
        for(int j = 0; j < k; j++)
        {
            v[j] += cookies[i];
            ans = min(ans, dfs(i+1, cookies, v, k));
            v[j] -= cookies[i];
        }
        return ans;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> v(k, 0);
        return dfs(0, cookies, v, k);
    }
};