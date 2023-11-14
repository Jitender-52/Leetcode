class Solution {
public:
    
//     Runtime: 630 ms, faster than 33.79% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 13.6 MB, less than 52.05% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
    
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int ans = 0;
        for(char c = 'a'; c <= 'z'; c++)
        {
            int i = 0;
            while(i < n && s[i] != c)
                i++;
            int j = n-1;
            while(j > i && s[j] != c)
                j--;
            set<char> st;
            for(int k = i+1; k < j; k++)
                st.insert(s[k]);
            ans += st.size();
        }
        return ans;
    }
};