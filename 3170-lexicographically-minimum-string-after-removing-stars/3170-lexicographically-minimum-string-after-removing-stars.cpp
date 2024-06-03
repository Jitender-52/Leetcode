class Solution {
public:
    
    string clearStars(string s) {
        int n = s.length();
        map<char, vector<int>> mp;
        string x = s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '*')
            {
                auto &v = mp.begin()->second;  // my bad not using & here
                x[v.back()] = '*';
                v.pop_back();
                if(v.size() == 0)
                    mp.erase(mp.begin());
            }
            else
                mp[s[i]].push_back(i);
        }
        string ans = "";
        for(auto i : x)
        {
            if(i != '*')
                ans += i;
        }
        return ans;
    }
};
    
//     string clearStars(string s) {
//         int n = s.length();
//         multiset<char> st;
//         vector<char> v(n, '*');
//         for(int i = 0; i < n; i++)
//         {
//             if(s[i] == '*')
//             {
//                 v[i] = *st.begin();
//                 st.erase(st.begin());
//             }
//             else
//                 st.insert(s[i]);
//         }
        
//         char last = '.';
//         for(int i = n-1; i >= 0; i--)
//         {
//             if(last == s[i])
//             {
//                 s[i] = '*';
//                 last = '*';
//             }
//             if(v[i] != '*')
//                 last = v[i];
//         }
//         cout << s << endl;
//         string ans = "";
//         for(auto i : s)
//         {
//             if(i != '*')
//                 ans += i;
//         }
//         return ans;
//     }
// };

// "aaba*"
// "abc"
// "de*"
// "dk**"