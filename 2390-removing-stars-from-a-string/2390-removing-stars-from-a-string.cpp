class Solution {
public:
    
//     Runtime: 108 ms, faster than 16.98% of C++ online submissions for Removing Stars From a String.
// Memory Usage: 27 MB, less than 44.03% of C++ online submissions for Removing Stars From a String.

    
    
    string removeStars(string s) {
        stack<char> st;
        for(auto i : s)
        {
            if(!st.empty() && i == '*')
                st.pop();
            else
                st.push(i);
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};