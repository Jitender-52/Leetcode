class Solution {
public:
    
        int minimum(int i, char first, char last, vector<string> &words, vector<vector<vector<int>>> &dp)
        {
            int n = words.size();
            if(i >= n)
                return 0;
            if(dp[i][first-'a'][last-'a'] != -1)
                return dp[i][first-'a'][last-'a'];
            
            int ans1, ans2;
            int sz = words[i].size();
            
            // When word is kept first and then ans string;
            ans1 = sz + minimum(i+1, words[i][0], last, words, dp);
            if(words[i][sz-1] == first)
                ans1--;
            
            // when ans string is kept first and then word
            ans2 = sz + minimum(i+1, first, words[i][sz-1], words, dp);
            if(words[i][0] == last)
                ans2--;
            
            return dp[i][first-'a'][last-'a'] = min(ans1, ans2);               
        }
    
        int minimizeConcatenatedLength(vector<string>& words) {
            int n = words.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>> (26, vector<int> (26, -1)));
            return words[0].size() + minimum(1, words[0][0], words[0].back(), words, dp);
        }
};
    
    
    
//     int minimizeConcatenatedLength(vector<string>& words) {
//         int n = words.size();
//         map<char,int> mp, mp2;
//         for(int i = 0; i < n; i++)
//         {
//                         int m = words[i].length();
//             // for(int j = 0; j < words[i].length(); j++)
//                 mp[words[i][0]]++;
//                 mp[words[i][m-1]]++;  
//         }
        
// //         int ans = 0;
// //         for(int i = 0; i < n; i++)
// //         {
// //             int m = words[i].length();
// //             mp1[words[i][0]]++;
// //             mp2[words[i][m-1]]++;
// //             ans += m;
// //         }
        
// //         for(auto i : mp1)
// //         {
// //             ans -= min(i.second, mp2[i.first]);
// //         }
// //         return ans;
    
//         // int vis[n+5];
//             int count = 0;
//         vector<int> vis(n+2, 0);
        
//         string s = words[0];
//         int ans = (int)words[0].length();
//         vis[0] = 1;
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(!vis[j])
//                 {
//                     int m = words[j].length();
//                     // int p = s.length();
//                     if(mp[words[j][0]] > 1 && s[m-1] == words[j][0])
//                     {
//                         ans += m-1;
//                         mp[words[j][0]]--;
//                         vis[j] = 1;
//                         s += words[j];
//                         count++;
//                         break;
//                     }
//                     else if(mp[words[j][m-1]] > 1 && s[0] == words[j][m-1])
//                     {
//                         ans += m-1;
//                         mp[words[j][m-1]]--;
//                         vis[j] = 1;
//                         s = words[j] + s;
//                         words[j] += s;
//                         s = words[j][0];
//                         count++;
//                         break;
//                     }
//                 }
//             }
//         // cout << ans << endl;
//     }
        
//         cout << s << endl;
//         ans = 0;
//         ans = (int)s.length();
//         for(int i = 0; i < n; i++)
//         {
//             cout << i << " " << vis[i] << endl;
//             if(!vis[i])
//                 ans += words[i].length();
//         }
//         return ans-count;
        
//     }
// };