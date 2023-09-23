class Solution {
public:
    
    static bool compare(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        unordered_map<string, int> dp;
        int res = 0;
        for (string w : words) {
            for (int i = 0; i < w.length(); i++) {
                string pre = w.substr(0, i) + w.substr(i + 1);
                dp[w] = max(dp[w], dp.find(pre) == dp.end() ? 1 : dp[pre] + 1);
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};
    
    
//     int solve(int i, int last, vector<string> &words, vector<vector<int>> &dp)
//     {
//         int n = words.size();
//         if(i >= n)
//             return 0;
//         if(dp[i][last] != -1)
//             return dp[i][last];
//         int ans = 0;
//         if(last == 1001)
//         {
//             ans = max(ans, 1 + solve(i+1, i, words, dp));
//             ans = max(ans, solve(i+1, last, words, dp));
//             return dp[i][last] = ans;
//         }
//         int count = 0;
//         int k = 0;
//         if(words[i].length() == words[last].length() + 1)
//         {
//             for(int j = 0; j < words[i].length() && k < words[last].length(); j++)
//             {
//                 if(words[i][j] == words[last][k])
//                     k++;
//             }
//             if(k == words[last].length() && words[i].length() == 1 + words[last].length())
//             {
//                 // cout << words[i] << " " << words[last] << endl;
//                 ans = max(ans, 1 + solve(i+1, i, words, dp));
//             }
//         }
//         ans = max(ans, solve(i+1, last, words, dp));
//         return ans;
//     }
    
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();
//         sort(words.begin(), words.end(), [&](const string &a, const string &b){
//             return a.length() < b.length();
//         });
//         vector<vector<int>> dp(n, vector<int> (1002, -1));
//         return solve(0, 1001, words, dp);
//     }
// };