class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < m; j++)
                count += mat[i][j];
            v.push_back({count, i});
        }
        
        sort(v.begin(), v.end(), [&](pair<int,int> &a, pair<int,int> &b){
           if(a.first == b.first)
               return a.second < b.second;
            return a.first < b.first;
        });
        
        vector<int> ans;
        for(int i = 0; i < k; i++)
            ans.push_back(v[i].second);
        return ans;
    }
};