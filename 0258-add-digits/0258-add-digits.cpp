class Solution {
public:
    
        int addDigits(int num) {
            return num == 0 ? 0 : 1 + (num - 1) % 9;
        }
};
    
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Add Digits.
// Memory Usage: 6 MB, less than 63.10% of C++ online submissions for Add Digits.
    
//     int addDigits(int num) {
//         while(num > 9)
//         {
//             int a = 0;
//             while(num > 0)
//             {
//                 a += num % 10;
//                 num /= 10;
//             }
//             num = a;
//         }
//         return num;
//     }
// };