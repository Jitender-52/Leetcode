class Solution {
public:
    
     void generate(int open, int close, string &s, vector<string> &ans, int max)
    {
        if(s.length() == 2 * max)
        {
            ans.push_back(s);
            return;
        }
        
        if(open < max)
        {
            s += '(';
            generate(open+1, close, s, ans, max);
            s.pop_back();
        }
        if(close < open)
        {
            s += ')';
            generate(open, close+1, s, ans, max);
            s.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ans;
        generate(0, 0, s, ans, n);
        return ans;
    }
};
    
//     Runtime: 6 ms, faster than 42.25% of C++ online submissions for Generate Parentheses.
// Memory Usage: 11.4 MB, less than 85.54% of C++ online submissions for Generate Parentheses.
    
//     void generate(int open, int close, string &s, vector<string> &ans, int max)
//     {
//         if(s.length() == 2 * max)
//         {
//             ans.push_back(s);
//             return;
//         }
        
//         if(close > open)
//             return;
        
//         if(open < max)
//         {
//             s += '(';
//             generate(open+1, close, s, ans, max);
//             s.pop_back();
//         }
//         if(close < max)
//         {
//             s += ')';
//             generate(open, close+1, s, ans, max);
//             s.pop_back();
//         }
//     }
    
//     vector<string> generateParenthesis(int n) {
//         string s = "";
//         vector<string> ans;
//         generate(0, 0, s, ans, n);
//         return ans;
//     }
// };
    
    
    
    
//     Runtime: 59 ms, faster than 5.01% of C++ online submissions for Generate Parentheses.
// Memory Usage: 51.1 MB, less than 5.03% of C++ online submissions for Generate Parentheses.
    
//     bool isValid(string &s)
//     {
//         int n = s.length();
//         int count = 0;
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] == '(')
//                 count++;
//             else
//                 count--;
//             if(count < 0)
//                 return 0;
//         }
//         return count == 0;
//     }
    
//     void generate(int n, string s, vector<string> &ans)
//     {
//         // cout << s.length() << endl;
//         // cout << s << endl << endl;
//         if(s.length() == 2 * n)
//         {
//             if(isValid(s))
//                 ans.push_back(s);
//             return;
//         }
        
//         s += '(';
//         generate(n, s, ans);
//         s.pop_back();
//         s += ')';
//         generate(n, s, ans);
//     }
    
//     vector<string> generateParenthesis(int n) {
//         string s = "";
//         vector<string> ans;
//         generate(n, s, ans);
//         return ans;
//     }
// };