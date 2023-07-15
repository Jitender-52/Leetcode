class Solution {
public:
    
        int countBits(long long n)
        {
            int count = 0;
            while(n > 0)
            {
                count += n % 2;
                n /= 2;
            }
            return count;
        }
    
        int makeTheIntegerZero(int num1, int num2) {
            if(num1 < num2)
                return -1;
            
            for(int i = 0; i < 70; i++)
            {
                long long a = num1 - num2 * 1LL * i;
                if(i <= a && countBits(a) <= i)
                    return i;
                // i <= a is used because we can make a by adding 1 a times and the number of bits should be <= i as we can use atmost i setBits to make the a
            }
            return -1;
        }
};
    
    
//     int makeTheIntegerZero(int num1, int num2) {
//         // if(num1 <= abs(num2))
//         //     return -1;
        
//         int a = 1;
//         // a = num1 - (num2);
        
//         for(int i = 1; i <= 100; i++)
//         {
//             num1 -= num2;
            
//             a = 1;
//             while(a <= num1)
//             {
//                 a *= 2;
//             }
            
//             int x = num1;
//             int count = 0;
//             while(x > 0)
//             {
//                 if(a <= x)
//                 {
//                     x -= a;
//                     count++;
//                 }
//                 a /= 2;
//             }
//             // cout << num1 << endl;
//             if(i <= count)
//             {
//                 return min(i+2, count+2);
//             }
            
//         }
        
//         return -1;
        
//         // while(a < num1)
//         //     a *= 2;
// //         while()
        
//         int ans = 1e9;
        
// //         for(int i = 0; i < 61; i++)
// //         {
            
// //         }
    
//         return ans;
        
//     }
// };