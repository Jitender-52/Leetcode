class Solution {
public:
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