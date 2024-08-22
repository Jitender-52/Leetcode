class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < 31; i++)
        {
            if(!(num & (1 << i)))
                sum += (1 << i);
            else
            {
                ans += sum;
                sum = 0;
            }
        }
        return ans;
    }
};