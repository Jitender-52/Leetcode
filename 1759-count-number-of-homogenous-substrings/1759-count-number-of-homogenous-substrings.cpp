class Solution {
public:
    
    const int mod = 1e9 + 7;
    
    int countHomogenous(string s) {
        int n = s.length();
        long long ans = 0;
        int i = 0;
        while(i < n)
        {
            char a = s[i];
            long long count = 0;
            while(i < n && s[i] == a)
            {
                count++;
                i++;
            }
            (ans += ((count) * (count + 1)) / 2) %= mod;
        }
        return ans;
    }
};