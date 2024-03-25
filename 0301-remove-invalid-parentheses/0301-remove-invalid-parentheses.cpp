class Solution {
public:
    
    set<string> st;
    
    int countRemovals(string &s)
    {
        stack<char> st;
        for(auto i : s)
        {
            if(i >= 'a' && i <= 'z')
                continue;
            if(i == '(')
                st.push(i);
            else if(st.empty() || st.top() == ')')
                st.push(i);
            else
                st.pop();
        }
        return st.size();
    }
    
    void solve(int i, int count, string &s, string &p, int removals)
    {
        int n = s.length();
        if(count == 0 && p.length() > 0 && removals == 0)
            st.insert(p);
        if(i >= n || count < 0 || removals < 0)
            return;
        if(s[i] == ')' || s[i] == '(')
            solve(i+1, count, s, p, removals - 1);
        p += s[i];
        if(s[i] == '(')
            solve(i+1, count+1, s, p, removals);
        else if(s[i] == ')')
            solve(i+1, count-1, s, p, removals);
        else
            solve(i+1, count, s, p, removals);
        p.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        string p = "";
        int removals = countRemovals(s);
        // cout << s.size() << " " << removals << " " << s.size() - removals << endl;
        solve(0, 0, s, p, removals);
        vector<string> ans;
        int maxi = 0;
        for(auto i : st)
            maxi = max(maxi, (int)i.length());
        for(auto i : st)
        {
            if(i.length() == maxi)
                ans.push_back(i);
        }
        if(ans.size() == 0)
            ans.push_back("");
        return ans;
    }
};