class Solution {
public:
    
//     Runtime: 3 ms, faster than 13.68% of C++ online submissions for Calculate Money in Leetcode Bank.
// Memory Usage: 6.4 MB, less than 15.79% of C++ online submissions for Calculate Money in Leetcode Bank.
    
    int totalMoney(int n) {
        int lastMonday = 0;
        int ans = 0, count = 0, money = 1;
        for(int i = 1; i <= n; i++)
        {
            if(count == 0)
            {
                money = lastMonday + 1;
                lastMonday = money;
            }
            ans += money;
            money++;
            count++;
            count %= 7;
        }
        return ans;
    }
};