class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n, 0), suffix(n, 0);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] ^ arr[i];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] ^ arr[i];
        vector<int> ans;
        for(auto v : queries)
        {
            int a = suffix[0];
            if(v[0] > 0)
                a ^= prefix[v[0] - 1];
            if(v[1] < n-1)
                a ^= suffix[v[1] + 1];
            ans.push_back(a);
        }
        return ans;
    }
};