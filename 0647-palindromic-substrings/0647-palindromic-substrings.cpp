class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int j = i-1, k = i;
            ans++; // for single character
            while(j >= 0 && k < n && s[j] == s[k]) // for even length substrings
            {
                j--;
                k++;
                ans++;
            }
            j = i-1, k = i+1;
            while(j >= 0 && k < n && s[j] == s[k]) // for odd length substrings
            {
                j--;
                k++;
                ans++;
            }
        }
        return ans;
    }
};