class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.length();
        int m = t.length();
        stack<char> st1, st2;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '#')
            {
                if(!st1.empty())
                    st1.pop();
            }
            else
            {
                st1.push(s[i]);
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(t[i] == '#')
            {
                if(!st2.empty())
                    st2.pop();
            }
            else
            {
                st2.push(t[i]);
            }
        }
        
        s = "", t = "";
        while(!st1.empty())
        {
            s += st1.top();
            st1.pop();
        }
        while(!st2.empty())
        {
            t += st2.top();
            st2.pop();
        }
        return s == t;
    }
};