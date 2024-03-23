class Solution {
public:
    
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = 0, y = 0;
        for(auto &i : arr1)
            x ^= i;
        for(auto &i : arr2)
            y ^= i;
        return (x & y);
    }
};
    
//     Runtime: 148 ms, faster than 8.27% of C++ online submissions for Find XOR Sum of All Pairs Bitwise AND.
// Memory Usage: 95.9 MB, less than 73.97% of C++ online submissions for Find XOR Sum of All Pairs Bitwise AND.
    
//     int getXORSum(vector<int>& arr1, vector<int>& arr2) {
//         int m = arr2.size();
//         vector<int> v(32, 0);
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < 32; j++)
//             {
//                 if((arr2[i] & (1 << j)) != 0)
//                     v[j]++;
//             }
//         }
        
//         int n = arr1.size();
//         vector<long long> bits(32, 0);
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < 32; j++)
//             {
//                 if((arr1[i] & (1 << j)) != 0)
//                 {
//                     int a = v[j];
//                     int b = m - v[j];
//                     bits[j] += v[j];
//                 }
//             }
//         }
        
//         int ans = 0;
//         for(int i = 0; i < 32; i++)
//         {
//             if(bits[i] % 2 == 1)
//                 ans += (1 << i);
//         }
//         return ans;
//     }
// };