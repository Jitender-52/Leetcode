class Solution {
public:
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