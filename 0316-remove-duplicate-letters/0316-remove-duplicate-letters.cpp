class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> v(26, 0);;
        for(int i = 0; i < n; i++)
        {
            v[s[i] - 'a'] = i;
        }
        
        vector<int> vis(26, 0);
        stack<char> st;
        for(int i = 0; i < s.size(); i++)
        {
            int a = s[i] - 'a';
            if(vis[a])
                continue;
            while(!st.empty() && v[st.top() - 'a'] > i && st.top() > s[i])
            {
                vis[st.top() - 'a'] = 0;
                st.pop();
            }
            vis[a] = 1;
            st.push(s[i]);
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Duplicate Letters.
// Memory Usage: 7.1 MB, less than 17.68% of C++ online submissions for Remove Duplicate Letters.

    
//     string removeDuplicateLetters(string s) {
//         vector<int> lastIndex(26, 0);
//         for (int i = 0; i < s.length(); i++)
//         {
//             lastIndex[s[i] - 'a'] = i; 
//         }
        
//         vector<bool> seen(26, false);
//         stack<char> st;
        
//         for (int i = 0; i < s.size(); i++) {
//             int curr = s[i] - 'a';
//             if(seen[curr]) 
//                 continue;
//             while(st.size() > 0 && st.top() > s[i] && i < lastIndex[st.top() - 'a'])
//             {
//                 seen[st.top() - 'a'] = false; 
//                 st.pop();
//             }
//             st.push(s[i]); 
//             seen[curr] = true; 
//         }
        
//         string ans = "";
//         while (st.size() > 0)
//         {
//             ans += st.top();
//             st.pop();
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };