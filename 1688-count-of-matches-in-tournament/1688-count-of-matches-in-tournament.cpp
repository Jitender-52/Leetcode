class Solution {
public:
    
    int numberOfMatches(int n) {
        return n-1;
    }
};

// Runtime: 3 ms, faster than 17.67% of C++ online submissions for Count of Matches in Tournament.
// Memory Usage: 6.3 MB, less than 73.09% of C++ online submissions for Count of Matches in Tournament.
    
//     int numberOfMatches(int n) {
//         int ans = 0;
//         while(n > 1)
//         {
//             ans += n / 2;
//             n = n / 2 + n % 2;
//         }
//         return ans;
//     }
// };