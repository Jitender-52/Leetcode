class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
// Memory Usage: 6 MB, less than 75.17% of C++ online submissions for Next Greater Element III.
    
        int nextGreaterElement(int n) {
            auto s = to_string(n);
            // next_permutation(begin(s), end(s));
            next_permutation(s.begin(), s.end()); // both methods work same
            auto ans = stoll(s);
            return (ans > INT_MAX || ans <= n) ? -1 : ans;
        }
};
    
    
    
//     Runtime: 3 ms, faster than 42.60% of C++ online submissions for Next Greater Element III.
// Memory Usage: 6.1 MB, less than 8.43% of C++ online submissions for Next Greater Element III.
    
    
//     int nextGreaterElement(int n) {
//         vector<int> v;
//         int m = n;
//         while(n != 0)
//         {
//             v.push_back(n % 10);
//             n /= 10;
//         }
//         n = v.size();
//         reverse(v.begin(), v.end());
        
//         for(int i = n-2; i >= 0; i--)
//         {
//             for(int j = n-1; j > i; j--)
//             {
//                 if(v[i] < v[j])
//                 {
//                     vector<int> v1 = v;
//                     swap(v1[i], v1[j]);
//                     sort(v1.begin()+i+1, v1.end());
//                     // break;
//                     long long ans = 0;
//                     for(int i = 0; i < n; i++)
//                     {
//                         ans = ans * 10 + v1[i];
//                     }
//                     if(ans <= INT_MAX && ans > m)
//                         return ans;
//                 }
//             }
//             // if(v[i] < v[i+1])
//             // {
//             //     swap(v[i], v[i+1]);
//             //     sort(v.begin()+i+1, v.end());
//             //     break;
//             // }
//         }
//         return -1;
//         // long long ans = 0;
//         // for(int i = 0; i < n; i++)
//         // {
//         //     ans = ans * 10 + v[i];
//         // }
//         // if(ans > INT_MAX || ans == m)
//         //     return -1;
//         // return ans;
//     }
// };

// 123