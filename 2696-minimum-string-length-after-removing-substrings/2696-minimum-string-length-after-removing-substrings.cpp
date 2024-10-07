class Solution {
public:
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