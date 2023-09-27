class Solution {
public:
    
    string decodeAtIndex(string s, int k) {
        int n = s.length();
        long long count = 0;
        for(int i = 0; i < n; i++)
        {
            if(isdigit(s[i]))
                count *= (s[i] - '0');
            else 
                count++;
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            k %= count;
            if(k == 0 && !isdigit(s[i]))
            {
                string ans = "";
                ans += s[i];
                return ans;
            }
            if(isdigit(s[i]))
                count /= (s[i] - '0');
            else
                count--;
        }
        return "";
    }
};

    
    
//     Runtime: 2 ms, faster than 45.12% of C++ online submissions for Decoded String at Index.
// Memory Usage: 6.4 MB, less than 11.71% of C++ online submissions for Decoded String at Index.
    
//     string decodeAtIndex(string s, int k) {
//         long long n = 0, i = 0;
//         for (i = 0; n < k; ++i)
//         {
//             if(isdigit(s[i]))
//                 n *= (s[i] - '0');
//             else
//                 n++;
//         }
//         while (i--)
//         {
//             if (isdigit(s[i]))
//             {
//                 n /= s[i] - '0';
//                 k %= n;
//             }
//             else if (k % n-- == 0)
//             {
//                 string ans = "";
//                 ans += s[i];
//                 return ans;
//             }
//         }
//         return "";

//     }
// };