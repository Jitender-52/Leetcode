class Solution {
public:
    
    char findTheDifference(string s, string t) {
        int a = 0;
        for(auto i : t)
            a += i - '0';
        for(auto i : s)
            a -= i - '0';
        return (a + '0');
    }
};
    
    
//     Runtime: 3 ms, faster than 65.73% of C++ online submissions for Find the Difference.
// Memory Usage: 7 MB, less than 8.68% of C++ online submissions for Find the Difference.
    
//     char findTheDifference(string s, string t) {
//         map<char, int> mp;
//         for(auto i : t)
//             mp[i]++;
//         for(auto i : s)
//             mp[i]--;
//         for(auto i : mp)
//         {
//             if(i.second)
//                 return i.first;
//         }
//         return '*';
//     }
// };