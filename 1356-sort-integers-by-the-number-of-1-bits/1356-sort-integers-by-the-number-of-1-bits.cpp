class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int a, int b){
            int x = __builtin_popcount(a), y = __builtin_popcount(b);
            if(x == y)
                return a < b;
            return x < y;
        });
        return arr;
    }
};
    
//     Runtime: 22 ms, faster than 6.90% of C++ online submissions for Sort Integers by The Number of 1 Bits.
// Memory Usage: 10.4 MB, less than 66.29% of C++ online submissions for Sort Integers by The Number of 1 Bits.
    
//     vector<int> sortByBits(vector<int>& arr) {
//         sort(arr.begin(), arr.end(), [&](int a, int b){
//             int x = 0, y = 0;
//             for(int i = 0; i < 20; i++)
//             {
//                 if((1 << i) & a)
//                     x++;
//                 if((1 << i) & b)
//                     y++;
//             }
//             if(x == y)
//                 return a < b;
//             return x < y;
//         });
//         return arr;
//     }
// };