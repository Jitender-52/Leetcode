class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        for(int i = 0; i < 31; i++)
        {
            bool a = start & (1 << i), b = goal & (1 << i);
            // cout << a << " " << b << endl;
            ans += (a ^ b);
        }
        return ans;
    }
};