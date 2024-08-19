class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        int a = 1;
        int i = 1;
        while(a < n)
        {
            if(n % a == 0)
            {
                i = a;
                a = 2 * i;
                ans += 2;
            }
            else
            {
                a += i;
                ans++;
            }
        }
        return ans;
    }
};