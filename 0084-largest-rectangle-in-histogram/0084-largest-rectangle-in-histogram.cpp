class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> suff(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(st.empty())
                suff[i] = n;
            else
                suff[i] = st.top();
            st.push(i);
        }
        
        stack<int> pref;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            while(!pref.empty() && heights[pref.top()] >= heights[i])
                pref.pop();
            int start = -1;
            if(!pref.empty())
                start = pref.top();
            ans = max(ans, (suff[i] - start - 1) * heights[i]);
            pref.push(i);
        }
        return ans;
    }
};