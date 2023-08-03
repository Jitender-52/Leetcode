class Solution {
public:
    
    void solve(int i, string &s, string &digits, vector<string> &v, vector<string> &ans)
    {
        int n = digits.size();
        if(i >= n)
        {
            if(s.length() > 0)
                ans.push_back(s);
            return;
        }
        for(auto j : v[digits[i] - '0'])
        {
            s.push_back(j);
            solve(i+1, s, digits, v, ans);
            s.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        string s = "";
        vector<string> ans;
        solve(0, s, digits, v, ans);
        return ans;
    }
};