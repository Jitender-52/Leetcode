class Solution {
public:
    
    
      long getSum(int index, int value, int n) {
        long count = 0;
        
        // On index's left:
        // If value > index, there are index + 1 numbers in the arithmetic sequence:
        // [value - index, ..., value - 1, value].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [1, 2, ..., value - 1, value], plus a sequence of length (index - value + 1) of 1s. 
        if (value > index) {
            count += (long)(value + value - index) * (index + 1) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + index - value + 1;
        };
        // On index's right:
        // If value >= n - index, there are n - index numbers in the arithmetic sequence:
        // [value, value - 1, ..., value - n + 1 + index].
        // Otherwise, there are value numbers in the arithmetic sequence:
        // [value, value - 1, ..., 1], plus a sequence of length (n - index - value) of 1s. 
        if (value >= n - index) {
            count += (long)(value + value - n + 1 + index) * (n - index) / 2;
        } else {
            count += (long)(value + 1) * value / 2 + n - index - value;
        }   
        
        return count - value;
        
    }
     int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (getSum(index, mid, n) <= maxSum) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
};
    
    
//     int find(int mid, int index)
//     {
//         int sum = 0;
        
//         sum = (mid * (mid - 1)) / 2;
//         int a = mid - index - 1;
//         cout << "sum = " << a << " " << sum << " ";
//         if(a > 0)
//         {
//             sum -= (a * (a + 1)) / 2;
//         }
//         else
//         {
//             sum += abs(a) + 1;
//         }
        
//         cout << sum << endl;
        
//         return sum;
        
//         // if(mid - (index + 1) <= 0)
//         // {
//         //     sum += (mid * (mid + 1)) / 2;
//         //     sum += index + 1 - mid;
//         //     cout << 1 << " " << sum << endl;
//         // }
//         // else 
//         // {
//         //     sum += (mid * (mid + 1)) / 2;
//         //     int a = mid - (index);
//         //     sum -= (a * (a + 1)) / 2;
//         //     cout << 2 <<  " " << sum << endl;
//         // }
//         // return sum;
//     }
    
//     bool isFeasible(int mid, int n, int index, int maxSum)
//     {
//         int a = find(mid, index + 1);
//         int b = find(mid, n - index); // index no. from back;
//         int sum = a + b - mid;   // -mid becuse mid value is added twice;
//         cout << a << " " << b << " " << mid << endl;
//         cout << n - index - 1 << endl;
//         return sum <= maxSum;
//     }
    
//     int maxValue(int n, int index, int maxSum) {
//         int low = 0, high = maxSum;
//         while(low <= high)
//         {
//             int mid = (low + high) / 2;
//             cout << mid << " ";
//             if(isFeasible(mid, n, index, maxSum))
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//             cout << endl;
//         }
//         return low - 1;
//     }
// };

// 1 2 3
// 1 1 1 2 3
// 3 4 5
