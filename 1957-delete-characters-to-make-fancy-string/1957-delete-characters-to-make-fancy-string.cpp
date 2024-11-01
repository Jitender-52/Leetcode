class Solution {
public:
    
//     Runtime: 32 ms, faster than 38.96% of C++ online submissions for Delete Characters to Make Fancy String.
// Memory Usage: 42.6 MB, less than 77.67% of C++ online submissions for Delete Characters to Make Fancy String.
    
    string makeFancyString(string s) {
        int n = s.length();
        if(n <= 2)
            return s;
        string ans = "";
        ans += s[0];
        ans += s[1];
        for(int i = 2; i < n; i++)
        {
            if(s[i] != s[i-1] || s[i] != s[i-2])
                ans += s[i];
        }
        return ans;
    }
};