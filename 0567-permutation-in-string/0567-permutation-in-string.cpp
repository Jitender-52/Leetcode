class Solution {
public:
    
//     Runtime: 2265 ms, faster than 5.02% of C++ online submissions for Permutation in String.
// Memory Usage: 93.3 MB, less than 5.01% of C++ online submissions for Permutation in String.
    
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s1[i]]++;
        }
        for(int i = 0; i <= m - n; i++)
        {
            unordered_map<char,int> mp1;
            for(int j = i; j < i + n; j++)
            {
                // cout << j <<" ";
                mp1[s2[j]]++;
            }
            // cout << endl;
            if(mp == mp1)
                return true;
        }
        return false;
    }
};