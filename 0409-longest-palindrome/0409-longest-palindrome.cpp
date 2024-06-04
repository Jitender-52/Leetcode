class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto i : s)
            mp[i]++;
        int odd = 0, even = 0;
        for(auto i : mp)
        {
            even += i.second - i.second % 2;
            odd += i.second % 2;
        }
        return even + (odd > 0);
    }
};