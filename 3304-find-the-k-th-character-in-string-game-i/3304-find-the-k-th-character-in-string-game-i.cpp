class Solution {
public:
    char kthCharacter(int k) {
        long long ans = 0;
        k--;
        for(long long i = 0; i <= log2(k); i++)
        {
            if(k & (1LL << i))
                ans++;
        }
        return ('a' + ans % 26);
    }
};