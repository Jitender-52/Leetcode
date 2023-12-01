class Solution {
public:
    
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n = word1.size(), m = word2.size();
        int i1 = 0, i2 = 0, j1 = 0, j2 = 0;
        while(i1 < n && i2 < m)
        {
            if(word1[i1][j1] != word2[i2][j2])
                return false;
            j1++;
            j2++;
            if(j1 == word1[i1].length())
            {
                j1 = 0;
                i1++;
            }
            if(j2 == word2[i2].length())
            {
                j2 = 0;
                i2++;
            }
        }
        return i1 == n && i2 == m;
    }
};
    
//     Runtime: 4 ms, faster than 57.15% of C++ online submissions for Check If Two String Arrays are Equivalent.
// Memory Usage: 12 MB, less than 31.59% of C++ online submissions for Check If Two String Arrays are Equivalent.
    
//     bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
//         string s1 = "", s2 = "";
//         for(auto i : word1)
//             s1 += i;
//         for(auto i : word2)
//             s2 += i;
//         return s1 == s2;
//     }
// };