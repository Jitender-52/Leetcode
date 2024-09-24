class Solution {
public:

//     Runtime: 26 ms, faster than 24.61% of C++ online submissions for Minimum Window Substring.
// Memory Usage: 10.6 MB, less than 7.76% of C++ online submissions for Minimum Window Substring.
    
     string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> dictT;
        for (char c : t) {
            int count = dictT[c];
            dictT[c] = count + 1;
        }

        int required = dictT.size();
        int l = 0, r = 0;
        int formed = 0;

        unordered_map<char, int> windowCounts;
        int ans[3] = {-1, 0, 0};

        while (r < s.length()) {
            char c = s[r];
            int count = windowCounts[c];
            windowCounts[c] = count + 1;
            if (dictT.find(c) != dictT.end() && windowCounts[c] == dictT[c]) {
                formed++;
            }
            while (l <= r && formed == required) {
                c = s[l];

                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowCounts[c]--;
                if (dictT.find(c) != dictT.end() && windowCounts[c] < dictT[c]) {
                    formed--;
                }

                l++;
            }
            r++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};
    
//     string minWindow(string s, string t) {
//         int n = s.length();
//         int m = t.length();
//         if(n < m)
//             return "";
        
//         unordered_map<char,int> mp;
        
//         for(int i = 0; i < m; i++)
//         {
//             mp[t[i]]++;
//         }
        
//         int j = 0;
        
//         unordered_map<char,int> mp1;
//         string ans = s;
//         ans += 'a';
//         for(int i = 0; i < n;  i++)
//         {
//             mp1[s[i]]++;
//             while(mp1.size() >= mp.size() && j < n)
//             {
//                 bool check = true;
//                 for(auto it : mp)
//                 {
//                     if(it.second > mp1[it.first])
//                     {
//                         check = false;
//                     }
//                 }
//                 if(check)
//                 {
//                     if(i-j+1 < ans.length())
//                         ans = s.substr(j, i-j+1);
//                     mp1[s[j]]--;
//                        if(mp1[s[j]] == 0)
//                        {
//                            mp1.erase(s[j]);
//                        }
//                     j++;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         if(ans.length() > n)
//             return "";
        
//         return ans;
//     }
// };
    
//     string minWindow(string s, string t) {
//         int n = s.length();
//         map<char, int> mp1, mp2;
//         for(auto i : t)
//             mp2[i]++;
        
//         int j = 0, l = -1, r = n, maxi = n+1;
//         for(int i = 0; i < n; i++)
//         {
//             if(mp2.find(s[i]) != mp2.end())
//                 mp1[s[i]]++;
//             bool check = true;
//             while(check && j < n)
//             {
//                 for(auto j : mp2)
//                 {
//                     if(mp1[j.first] < j.second)
//                     {
//                         check = false;
//                         break;
//                     }
//                 }
//                 if(!check)
//                     break;
//                 if(i-j+1 < maxi)
//                 {
//                     l = j;
//                     r = i;
//                     maxi = i-j+1;
//                 }
//                 if(mp2.find(s[j]) != mp2.end())
//                 {
//                     mp2[s[j]]--;
//                     if(mp2[s[j]] == 0)
//                         mp2.erase(s[j]);
//                 }
//                 j++;
//             }
//         }
        
//         if(l == -1)
//             return "";
//         return s.substr(l, r-l+1);
//     }
// };
    
//     string minWindow(string s, string t) {
//         int n = s.length();
//         // set<char> st;
//         map<char, int> st;
//         for(auto i : t)
//             st[i]++;
//         //     st.insert(i);
//         map<char,int> mp;
//         int j = 0;
//         int l = -1, r = n;
//         int maxi = n+1;
//         for(int i = 0; i < n; i++)
//         {
//             if(st.find(s[i]) != st.end())
//                 mp[s[i]]++;
//             // cout << i << " " << l << " " << r << " " << mp.size() << endl;
//             // cout << i << " " << l << " " << r << endl;
//             // cout << i << " " << mp.size() << endl;
//             while(mp.size() == st.size())
//             {
//                 if(i - j + 1 < maxi)
//                 {
//                     cout << i << " " << j << endl;
//                     cout << "HII" << endl;
//                     bool check = true;
//                     for(auto i : st)
//                     {
//                         if(i.second > mp[i.first])
//                             check = false;
//                     }
//                     if(check)
//                     {
//                         maxi = i - j + 1;
//                         l = j;
//                         r = i;
//                     }
//                     // cout << l << " " << r << endl;
//                 }
//                 // cout << i << " " << l << " " << r << " " << mp.size() << endl;
//                 if(st.find(s[j]) == st.end())
//                 {
//                     j++;
//                     continue;
//                 }
//                 mp[s[j]]--;
//                 if(mp[s[j]] == 0)
//                     mp.erase(s[j]);
//                 j++;
//             }
//         }
//         if(l == -1)
//             return "";
//         return s.substr(l, r-l+1);
//     }
// };