class Solution {
public:
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