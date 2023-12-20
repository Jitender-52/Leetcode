class Solution {
public:
    
//     Runtime: 19 ms, faster than 19.09% of C++ online submissions for Buy Two Chocolates.
// Memory Usage: 46.9 MB, less than 58.30% of C++ online submissions for Buy Two Chocolates.
    
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int ans = money - (prices[1] + prices[0]);
        if(ans < 0)
            return money;
        return ans;
    }
};