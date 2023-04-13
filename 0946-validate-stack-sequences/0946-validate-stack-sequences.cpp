class Solution {
public:
    
//     Runtime: 15 ms, faster than 18.21% of C++ online submissions for Validate Stack Sequences.
// Memory Usage: 15.5 MB, less than 24.28% of C++ online submissions for Validate Stack Sequences.
    
    
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0;
        int j = 0;
        stack<int> st;
        while(i < n)
        {
            while(!st.empty() && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            st.push(pushed[i]);
            i++;
        }
        while(!st.empty() && st.top() == popped[j])
        {
            st.pop();
            j++;
        }
        return st.empty();
    }
};