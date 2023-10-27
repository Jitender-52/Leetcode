class Solution {
public:
    
    int longest(string &s, int i, int j)
    {
        int n = s.length();
        while(i >= 0 && j < n)
        {
            if(s[i] != s[j])
                break;
            i--;
            j++;
        }
        return j - i - 1;
    }
    
    string longestPalindrome(string s) {
        int n = s.length();
        
        int start = 0, end = 0;
        for(int i = 0; i < n; i++)
        {
            int l1 = longest(s, i, i);
            int l2 = longest(s, i, i+1);
            int l = max(l1, l2);
            if(l > end - start + 1)
            {
                start = i - ((l - 1) / 2);
                end = i + (l / 2);
            }
        }
        string ans = "";
        for(int i = start; i <= end; i++)
            ans += s[i];
        return ans;
    }
};
    
//     bool isPalindrome(string s)
//     {
//         string t = s;
//         reverse(t.begin(), t.end());
//         return s == t;
//     }
    
//     string longestPalindrome(string s) {
//         int n = s.length();
//         string ans = "";
//         for(int i = 0; i < n; i++)
//         {
//             string x = "";
//             for(int j = i; j < n; j++)
//             {
//                 x += s[j];
//                 if(isPalindrome(x) && x.length() > ans.length())
//                     ans = x;
//             }
//         }
//         return ans;
//     }
// };