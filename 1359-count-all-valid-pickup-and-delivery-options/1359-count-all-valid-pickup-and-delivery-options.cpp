class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        long long i = 1;
        while (n != 0)
        {
            ans = ans * n * i;
            ans = ans % 1000000007;
            i += 2;
            n--;
        }
        return ans;
    }
};
