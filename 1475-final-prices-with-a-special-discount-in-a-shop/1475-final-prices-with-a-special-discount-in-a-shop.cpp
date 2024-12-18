class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Final Prices With a Special Discount in a Shop.
// Memory Usage: 14.4 MB, less than 9.86% of C++ online submissions for Final Prices With a Special Discount in a Shop.
    
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans = prices;
        stack<int> st;
        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) 
            {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};