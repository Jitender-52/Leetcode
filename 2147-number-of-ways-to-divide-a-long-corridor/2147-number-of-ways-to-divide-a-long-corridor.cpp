class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int numberOfWays(string corridor) {
        int n = corridor.size();
        int i = 0; 
        int count = 0, count2 = 1, count3 = 0;
        long long ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(corridor[i] == 'S')
            {
                if(count == 0 && count3 > 0)
                    (ans *= 1LL * count2) %= mod;
                count2 = 1;
                count++;
                count3++;
            }
            if(count == 2)
            {
                count = 0;
                count2 = 1;
            }
            if(corridor[i] == 'P')
                count2++;
        }
        if(count3 % 2 == 1 || count3 == 0)
            return 0;
        return ans;
    }
};