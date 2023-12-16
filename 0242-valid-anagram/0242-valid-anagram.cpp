class Solution {
public:
    
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for(int i = 0; i < s.length(); i++)
            v[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++)
        {
            v[t[i] - 'a']--;
            if(v[t[i] - 'a'] < 0)
                return false;
        }
        for(int i = 0; i < 26; i++)
        {
            if(v[i] != 0)
                return false;
        }
        return true;
    }   
};
    
//     Runtime: 3 ms, faster than 97.78% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.7 MB, less than 45.96% of C++ online submissions for Valid Anagram.
    
//     bool isAnagram(string s, string t) {
//         vector<int> v(26, 0);
//         for(int i = 0; i < s.length(); i++)
//             v[s[i] - 'a']++;
//         for(int i = 0; i < t.length(); i++)
//             v[t[i] - 'a']--;
//         for(int i = 0; i < 26; i++)
//         {
//             if(v[i] != 0)
//                 return false;
//         }
//         return true;
//     }   
// };