class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string ans = "";
        for(auto i : s)
        {
            if(i == '(')
                st.push(ans.length());
            else if(i == ')')
            {
                reverse(ans.begin() + st.top(), ans.end());
                st.pop();
            }
            else
                ans += i;
        }
        return ans;
    }
};