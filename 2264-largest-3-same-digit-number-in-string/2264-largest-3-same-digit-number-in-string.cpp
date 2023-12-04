class Solution {
public:
    
    string largestGoodInteger(string num) {
        int n = num.size();
        char a = '*';
        for(int i = 1; i < n-1; i++)
        {
            if(num[i] == num[i-1] && num[i] == num[i+1])
            {
                if(a == '*')
                    a = num[i];
                else
                    a = max(a, num[i]);
            }
        }
        return (a == '*') ? "" : string(3, a);
    }
};
    
    
//     Runtime: 4 ms, faster than 47.83% of C++ online submissions for Largest 3-Same-Digit Number in String.
// Memory Usage: 6.9 MB, less than 31.59% of C++ online submissions for Largest 3-Same-Digit Number in String.

    
//     string largestGoodInteger(string num) {
//         int n = num.size();
//         char a = '*';
//         for(int i = 1; i < n-1; i++)
//         {
//             if(num[i] == num[i-1] && num[i] == num[i+1])
//             {
//                 if(a == '*')
//                     a = num[i];
//                 else
//                     a = max(a, num[i]);
//             }
//         }
//         if(a == '*')
//             return "";
//         string ans = "";
//         for(int i = 0; i < 3; i++)
//             ans += a;
//         return ans;
//     }
// };