class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
// Memory Usage: 7.8 MB, less than 52.67% of C++ online submissions for Reverse Substrings Between Each Pair of Parentheses.
    
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