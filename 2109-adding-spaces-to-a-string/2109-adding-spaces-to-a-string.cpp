class Solution {
public:
    
//     Runtime: 630 ms, faster than 5.12% of C++ online submissions for Adding Spaces to a String.
// Memory Usage: 208.5 MB, less than 5.31% of C++ online submissions for Adding Spaces to a String.
    
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length();
        map<int,int> mp;
        for(int i = 0; i < spaces.size(); i++)
            mp[spaces[i]] = 1;
        
        string ans = "";
        if(mp[0] == 1)
            ans += " ";
        
        for(int i = 0; i < n; i++)
        {
            ans += s[i];
            if(mp[i + 1] == 1)
                ans += " ";
        }
        return ans;
    }
};