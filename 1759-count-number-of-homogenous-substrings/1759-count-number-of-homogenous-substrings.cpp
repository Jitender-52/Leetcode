class Solution {
public:
    
//     Runtime: 25 ms, faster than 63.26% of C++ online submissions for Count Number of Homogenous Substrings.
// Memory Usage: 12.3 MB, less than 16.96% of C++ online submissions for Count Number of Homogenous Substrings.

    
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