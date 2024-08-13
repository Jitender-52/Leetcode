class Solution {
public:
    
//     Runtime: 38 ms, faster than 6.04% of C++ online submissions for Combination Sum II.
// Memory Usage: 24.1 MB, less than 6.67% of C++ online submissions for Combination Sum II.
    
    void combine(int i, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> v, int sum)
    {
        v.push_back(candidates[i]);
        sum += candidates[i];
        if(sum > target)
        {
            return;
        }
        if(sum == target)
        {
            // cout << "HII" << endl;
            // if(v[i])
            ans.push_back(v);
            return;
        }
        int n = candidates.size();
        if(i >= candidates.size())
        {
            return;
        }
        for(int j = i + 1; j < n; j++)
        {
            // if(candidates[j] == candidates[j - 1])
            // {
            //     continue;
            // }
            // v.push_back(candidates[j]);
                // sum += candidates[j];
            combine(j, candidates, target, ans, v, sum);
            while(j < n -1 && candidates[j + 1] == candidates[j])
            {
                j++;
            }
            // sum -= candidates[j];
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        int sum = 0;
        vector<vector<int>> ans;
        for(int i = 0; i < candidates.size(); i++)
        {
            if(i > 0 && candidates[i] == candidates[i-1])
            {
                continue;
            }
            combine(i, candidates, target, ans, v, sum);
        }
        return ans;
    }
};