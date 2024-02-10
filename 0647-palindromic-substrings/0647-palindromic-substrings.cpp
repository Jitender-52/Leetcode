class Solution {
public:
    
//     Runtime: 4 ms, faster than 76.20% of C++ online submissions for Palindromic Substrings.
// Memory Usage: 7.3 MB, less than 78.14% of C++ online submissions for Palindromic Substrings.
    
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int j = i-1, k = i;
            ans++;
            while(j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
                ans++;
            }
            j = i-1, k = i+1;
            while(j >= 0 && k < n && s[j] == s[k])
            {
                j--;
                k++;
                ans++;
            }
        }
        return ans;
    }
};