class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(), prices.end());
        int ans = money - (prices[1] + prices[0]);
        if(ans < 0)
            return money;
        return ans;
    }
};