class Solution {
public:
    
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        if(n == 1)
            return ans;
        
        for(int i = n-1; i >= 0; i--)
        {
            int cnt=1;
            while(!st.empty() && heights[i] >= st.top())
            {
               st.pop();
               cnt++;
            }
            ans[i] = cnt;
            if(st.empty())
               ans[i] = cnt-1;
            st.push(heights[i]); 
        }
        return ans;
    }
};