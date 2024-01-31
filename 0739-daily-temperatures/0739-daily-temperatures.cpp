class Solution {
public:
    
//     Runtime: 129 ms, faster than 80.09% of C++ online submissions for Daily Temperatures.
// Memory Usage: 105.3 MB, less than 28.03% of C++ online submissions for Daily Temperatures.
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};