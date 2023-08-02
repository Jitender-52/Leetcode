class Solution {
public:
    void nextPermutation(vector<int> &v, vector<vector<int>> &ans)
    {
        int n = v.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i] < v[i + 1])
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            sort(v.begin(), v.end());
            ans.push_back(v);
            return;
        }
        sort(v.begin() + idx + 1, v.end());

        for (int i = idx; i < n; i++)
        {
            if (v[i] > v[idx])
            {
                swap(v[i], v[idx]);
                ans.push_back(v);
                return;
            }
        }
        ans.push_back(v);
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);

        do
        {

            vector<int> v = ans[ans.size() - 1];
            nextPermutation(v, ans);

        } while (ans[ans.size() - 1] != nums);
        ans.pop_back();
        return ans;
    }
    
};