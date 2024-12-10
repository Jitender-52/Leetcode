class Solution {
public:
    
//     Runtime: 618 ms, faster than 5.49% of C++ online submissions for Find Longest Special Substring That Occurs Thrice I.
// Memory Usage: 232.1 MB, less than 5.04% of C++ online submissions for Find Longest Special Substring That Occurs Thrice I.
    
    int maximumLength(string s) {
        int n = s.length();
        // string ans = "";
        int ans = -1;
        for(int i = n; i > 0; i--)
        {
            map<string, int> mp;
            for(int j = 0; j <= n - i; j++)
            {
                string x = s.substr(j, i);
                set<char> st;
                for(auto it : x)
                    st.insert(it);
                if(st.size() != 1)
                    continue;
                mp[s.substr(j, i)]++;
            }
            for(auto i : mp)
            {
                if(i.second >= 3)
                {
                    // cout << i.first << endl;
                    ans = max(ans, (int)i.first.length());
                    // ans = i.first;
                    // return ans.length();
                }
            }
        }
        // cout << endl;
        return ans;
        // cout << ans << endl;
        // if(ans == "")
        //     return -1;
        // return ans.length();
    }
};