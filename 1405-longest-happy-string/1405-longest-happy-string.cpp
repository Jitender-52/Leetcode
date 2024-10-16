class Solution{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int counta = 0, countb = 0, countc = 0;
        int totalIterations = a + b + c;
        string ans = "";

        for (int i = 0; i < totalIterations; i++)
        {
            if ((a >= b and a >= c and counta != 2) || (a > 0 and (countb == 2 || countc == 2)))
            {
                ans += 'a';
                a--;
                counta++;
                countb = 0;
                countc = 0;
            }
            else if ((b >= a and b >= c and countb != 2) || (b > 0 and (countc == 2 || counta == 2)))
            {
                ans += 'b';
                b--;
                countb++;
                counta = 0;
                countc = 0;
            }
            else if ((c >= a and c >= b and countc != 2) || (c > 0 and (counta == 2 || countb == 2)))
            {
                ans += 'c';
                c--;
                countc++;
                counta = 0;
                countb = 0;
            }
        }
        return ans;
    }
};    
    
//     string longestDiverseString(int a, int b, int c) {
//         string ans = "";
//         while(a > 0 || b > 0 || c > 0)
//         {
//             cout << a << " " << b << " " << c << endl;
//             if(a >= b && a >= c)
//             {
//                 for(int i = 0; i < 2 && a > 0; i++, a--)
//                 {
//                     ans += 'a';
//                 }
//                 if(b > 0 && b > c)
//                 {
//                     ans += 'b';
//                     b--;
//                 }
//                 else if(c > 0)
//                 {
//                     ans += 'c';
//                     c--;
//                 }
//             }
//             else if(b >= a && b >= c)
//             {
//                 for(int i = 0; i < 2 && b > 0; i++, b--)
//                 {
//                     ans += 'b';
//                 }
//                 if(a > c)
//                 {
//                     ans += 'a';
//                     a--;
//                 }
//                 else
//                 {
//                     ans += 'c';
//                     c--;
//                 }
//             }
//             else
//             { 
//                 for(int i = 0; i < 2 && c > 0; i++, c--)
//                 {
//                     ans += 'c';
//                 }
//                 if(a > b)
//                 {
//                     ans += 'a';
//                     a--;
//                 }
//                 else
//                 {
//                     ans += 'b';
//                     b--;
//                 }
//             }
//             cout << ans << endl;
//         }
//         int count = 1;
//         cout << ans << endl;
//         for(int i = 1; i < ans.length(); i++)
//         {
//             if(ans[i] == ans[i-1])
//                 count++;
//             else
//                 count = 1;
//             if(count >= 3)
//                 return "";
//         }
//         return ans;
//     }
// };