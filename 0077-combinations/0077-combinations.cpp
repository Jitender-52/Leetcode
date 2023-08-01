class Solution {
public:
    
    void combinations(int i, int n, int k, vector<vector<int>> &ans, vector<int> &v)
{
    if (i > n)
    {
        return;
    }
    if (v.size() == k)
    {
        ans.push_back(v);
        return;
    }

    for (i; i < n; i++)
    {
        v.push_back(i + 1);
        combinations(i + 1, n, k, ans, v);
        v.pop_back();
    }
}
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
    vector<int> v;
    int i = 0;
    combinations(i, n, k, ans, v);
    return ans;   
    }
};