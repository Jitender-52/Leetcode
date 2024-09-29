class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long ans = 0;
        k--;
        for(long long i = 0; i <= log2(k); i++)
        {
            if(k & (1LL << i))
                ans += operations[i];
        }
        return ('a' + ans % 26);
    }
};