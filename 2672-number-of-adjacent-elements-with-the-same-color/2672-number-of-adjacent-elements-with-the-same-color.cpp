class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<int> v(n, 0);
        
        int count = 0;
        vector<int> ans(q);
        for(int i = 0; i < q; i++)
        {
            int j = queries[i][0];
            int val = queries[i][1];
            if(j > 0 && v[j] != 0 && v[j] == v[j-1])
                count--;
            if(j < n-1 && v[j] != 0 && v[j] == v[j+1])
                count--;
            v[j] = val;
            if(j > 0 && v[j] == v[j-1])
                count++;
            if(j < n-1 && v[j] == v[j+1])
                count++;
            ans[i] = count;
        }
        return ans;
    }
};