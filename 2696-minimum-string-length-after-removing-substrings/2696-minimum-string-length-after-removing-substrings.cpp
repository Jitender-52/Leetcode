class Solution {
public:
    
//     Runtime: 3 ms, faster than 89.38% of C++ online submissions for Minimum String Length After Removing Substrings.
// Memory Usage: 11.7 MB, less than 31.24% of C++ online submissions for Minimum String Length After Removing Substrings.
    
    int minLength(string s) {
        int n = s.length();
        stack<char> st;
        for(int i = 0; i < n; i++)
        {
            if(st.size() < 1)
                st.push(s[i]);
            else if(s[i] == 'B')
            {
                if(st.top() == 'A')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else if(s[i] == 'D')
            {
                if(st.top() == 'C')
                    st.pop();
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);
        }
        return st.size();
    }
};