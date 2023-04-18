class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> ans;
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            ans.push_back(to_string(i + 1));
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < n; i++)
        {
            v.push_back(stoi(ans[i]));
        }
        return v;
    }
};
