class Solution {
public:
    
//     Runtime: 4 ms, faster than 39.51% of C++ online submissions for Valid Parentheses.
// Memory Usage: 6.2 MB, less than 97.19% of C++ online submissions for Valid Parentheses.
    
    
    bool isValid(string s) {
       int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            if(st.empty())
                st.push(s[i]);
            else if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']'))
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};