class Solution {
public:
    
//     Runtime: 9 ms, faster than 41.73% of C++ online submissions for Get Equal Substrings Within Budget.
// Memory Usage: 8.9 MB, less than 19.18% of C++ online submissions for Get Equal Substrings Within Budget.
    
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int sum = 0;
        int ans = 0;
        int i = 0, j = 0;
        while(i < n)
        {
            sum += abs(s[i] - t[i]);
            while(j < n && sum > maxCost)
            {
                sum -= (abs(s[j] - t[j]));
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};