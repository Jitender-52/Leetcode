class Solution {
public:
    
    bool isValid(string &s)
    {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;
            else
                count--;
            if(count < 0)
                return 0;
        }
        return count == 0;
    }
    
    void generate(int n, string s, vector<string> &ans)
    {
        // cout << s.length() << endl;
        // cout << s << endl << endl;
        if(s.length() == 2 * n)
        {
            if(isValid(s))
                ans.push_back(s);
            return;
        }
        
        s += '(';
        generate(n, s, ans);
        s.pop_back();
        s += ')';
        generate(n, s, ans);
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        generate(n, s, ans);
        return ans;
    }
};