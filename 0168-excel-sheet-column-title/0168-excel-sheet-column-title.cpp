class Solution {
public:
    
    string convertToTitle(int n) {
        string ans = "";
        while(n > 0)
        {
            n--;
            ans += ('A' + n % 26);
            n /= 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
    
    
//     string convertToTitle(int n) {
//         int a = 0;
//         int x = 1;
//         while( a <= n)
//         {
//             a += x;
//             x *= 26;
//         }
//         x /= 26;
        
//         string ans = "";
//         while(n > 0 && x > 0)
//         {
//             cout << x << endl;
//             a = n / x;
//             cout << a << endl;
//             if(a > 0)
//             {
//                 ans += ('A' + a-1);
//             }
//             if(x <= n)
//                 n -= a * x;
//             x /= 26;
//         }
//         return ans;
//     }
// };