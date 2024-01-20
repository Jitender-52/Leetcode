class Solution {
public:
    
    int mod = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> dp(n);

        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && arr[st.top()] > arr[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                dp[i] = dp[st.top()] + (i-st.top()) * arr[i];
            }  
            else
            {
                dp[i] = (i+1) * arr[i];
            }
            ans += dp[i];
            ans %= mod;
            st.push(i);
        }
        return ans;
    }
};