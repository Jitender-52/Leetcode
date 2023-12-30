class Solution {
public:
    
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> v(26, 0);
        for(auto i : words)
        {
            for(auto j : i)
                v[j-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(v[i] % n)
                return false;
        }
        return true;
    }
};
    
//     Runtime: 58 ms, faster than 5.06% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
// Memory Usage: 12.7 MB, less than 10.12% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
    
//     bool makeEqual(vector<string>& words) {
//         int n = words.size();
//         map<char, int> mp;
//         for(auto s : words)
//         {
//             for(auto c : s)
//                 mp[c]++;
//         }
//         for(auto i : mp)
//         {
//             if(i.second % n)
//                 return false;
//         }
//         return true;
//     }
// };