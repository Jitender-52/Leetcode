class Solution {
public:
    
    int passThePillow(int n, int time) {
        int t = 2 * n - 2;

        int a = time % t;

        if(a < n)
            return a + 1;
        return n - time % (n-1);
    }
};
    
    
//      int passThePillow(int n, int time) {
//         int tot=2*n-2;
//         time=time%tot;
//         if(time<=n-1)
//             return 1+time;
//         else
//             return n-time%(n-1);
//     }
// };
    
    
//     int passThePillow(int n, int time) {
//         // time++;
//         int x = 1;
//         bool check = false;
//         for(int i = 0; i < time; i++)
//         {
//             if(x == 1)
//             {
//                 check = true;
//             }
//             if(x == n)
//             {
//                 check = false;
//             }
//             if(check)
//             {
//                x++;
//             }
//             else
//             {
//                 x--;
//             }
//         }
//         return x;
//     }
// };