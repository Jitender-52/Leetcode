class Solution {
public:
    
    long long countSubstrings(string s, char c) {
        int count = 0;
        for(auto i : s)
            count += i == c;
        return (count * 1LL * (count+1)) / 2;
    }
};
    
//     Runtime: 28 ms, faster than 20.00% of C++ online submissions for Count Substrings Starting and Ending with Given Character.
// Memory Usage: 12.8 MB, less than 20.00% of C++ online submissions for Count Substrings Starting and Ending with Given Character.
    
//     long long countSubstrings(string s, char c) {
//         map<char,int> mp;
//         for(auto i : s)
//             mp[i]++;
//         return (mp[c] * 1LL * (mp[c]+1)) / 2;
//     }
// };