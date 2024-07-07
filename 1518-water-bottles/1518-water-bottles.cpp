class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles >= numExchange)
        {
            int x = numBottles / numExchange;
            ans += numExchange * x;
            numBottles -= numExchange * x;
            numBottles += x;
        }
        ans += numBottles;
        return ans;
    }
};