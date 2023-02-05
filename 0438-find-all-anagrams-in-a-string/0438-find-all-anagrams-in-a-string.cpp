class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        
        vector<int> ans;
        
        map<char,int> mp1;
        map<char,int> mp2;
        for(int i = 0; i < m; i++)
        {
            mp1[s[i]]++;
            mp2[p[i]]++;
        }
        
        int count = 0;
        char c = 'a';
        for(int i = 0; i < 26; i++)
        {
            if(mp1[c] == mp2[c])
                count++;
            c++;
        }
        
        int a = 0;
        if(count == 26)
            ans.push_back(a);
        
        for(int i = m; i < n; i++)
        {
            if(mp1[s[i]] == mp2[s[i]])
                count--;
            if(mp1[s[a]] == mp2[s[a]])
                count--;
            mp1[s[i]]++;
            mp2[s[a]]++;
            if(mp1[s[i]] == mp2[s[i]])
                count++;
            if(mp1[s[a]] == mp2[s[a]])
                count++;
            a++;
            if(count == 26)
                ans.push_back(a);
        }
        return ans;
    }
};