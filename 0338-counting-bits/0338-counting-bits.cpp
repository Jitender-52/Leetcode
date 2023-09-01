class Solution {
public:
    
   vector<int> countBits(int n) {
       vector<int> ans(n+1);
       for(int i = 0; i <= n; i++)
       {
           int count = 0;
           for(int j = 0; j < 20; j++)
           {
               if(i & 1 << j)
                   count++;
           }
           ans[i] = count;
       }
       return ans;
   }
};    
    
//     vector<int> countBits(int n) {
//         int a = 1, b = 0, c = 0;
//         vector<int> ans(n+1, 0);
//         for(int i = 1; i < n; i++)
//         {
//             cout << a << " " << b << " " << c << endl;
//             ans[i] = c;
//             if(c == a)
//             {
//                 a++;
//                 c = 1;
//                 b = -1;
//             }
//             else if(a == b)
//             {
//                 c++;
//                 b = -1;
//             }
//             else
//             {
//                 b++;
//             }
//         }
//         return ans;
//     }
// };