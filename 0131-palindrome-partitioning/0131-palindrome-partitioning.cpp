class Solution {
public:
    bool ispalindromic(string s)
    {
        for (int i = 0; i < (s.length() / 2) + 1; i++)
        {
            if (s[i] != s[s.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }

    void palindromic(int i, string s, vector<vector<string>> &ans, vector<string> v, string a)
    {
        if (i >= s.length())
        {
            ans.push_back(v);
            return;
        }
        for (int j = i; j < s.length(); j++)
        {
            a += s[j];
            if (ispalindromic(a))
            {
                v.push_back(a);
                string s1 = "";
                palindromic(j + 1, s, ans, v, s1);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        int i = 0;
        string a = "";
        palindromic(i, s, ans, v, a);
        return ans;
    }
};