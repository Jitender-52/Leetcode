class Solution {
public:
    
//     Runtime: 4 ms, faster than 34.51% of C++ online submissions for Find the Closest Palindrome.
// Memory Usage: 9.3 MB, less than 32.16% of C++ online submissions for Find the Closest Palindrome.
    
    string nearestPalindromic(string s) {
        int n = s.length();
        if (n == 1)
            return to_string(stol(s) - 1);

        vector<long long> v;

        v.push_back(pow(10, n - 1) - 1);
        v.push_back(pow(10, n) + 1);
        long long prefix = stol(s.substr(0, (n + 1) / 2));
        vector<long long> nearPrefixes = {prefix - 1, prefix, prefix + 1};

        for (auto it : nearPrefixes)
        {
            string prefix = to_string(it);
            if (n % 2)
                prefix.pop_back();
            reverse(prefix.begin(), prefix.end());
            v.push_back(stol(to_string(it) + prefix));
        }

        long long mini = LONG_MAX;
        long long close = 0;
        for (auto it : v)
        {
            long long diff = abs(it - stol(s));
            if (mini > diff && it != stol(s))
            {
                mini = diff;
                close = it;
            }
        }
        return to_string(close);
    }
};