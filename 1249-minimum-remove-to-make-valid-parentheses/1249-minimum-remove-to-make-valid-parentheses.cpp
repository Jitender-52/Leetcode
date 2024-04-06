class Solution {
public:
    
    
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        int count = 0;
        string ans = "";
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(')
                count++;
            else if(s[i] == ')')
            {
                if(count == 0)
                    s[i] = '*';
                else
                    count--;
            }
        }
        for(int i = n-1; i >= 0 && count > 0; i--)
        {
            if(s[i] == '(')
            {
                s[i] = '*';
                count--;
            }
        }
        for(auto &i : s)
        {
            if(i != '*')
                ans += i;
        }
        return ans;
    }
};
    
    
//     Runtime: 14 ms, faster than 95.19% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 12.8 MB, less than 56.98% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
    
//     string minRemoveToMakeValid(string s) {
//         int openParenthesesCount = 0;
//         vector<char> arr(s.begin(), s.end()); 
//         for (int i = 0; i < arr.size(); i++) {
//             if (arr[i] == '(')
//                 openParenthesesCount++;
//             else if (arr[i] == ')') {
//                 if (openParenthesesCount == 0)
//                     arr[i] = '*'; 
//                 else
//                     openParenthesesCount--;
//             }
//         }

//         for (int i = arr.size() - 1; i >= 0; i--) {
//             if (openParenthesesCount > 0 && arr[i] == '(') {
//                 arr[i] = '*'; 
//                 openParenthesesCount--;
//             }
//         }
        
//         string result = "";
//         for (char c : arr) {
//             if (c != '*')
//                 result += c;
//         }

//         return result;
//     }
// };