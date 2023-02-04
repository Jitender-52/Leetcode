class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        map<char,int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[s1[i]]++;
        }
        for(int i = 0; i <= m - n; i++)
        {
            map<char,int> mp1;
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