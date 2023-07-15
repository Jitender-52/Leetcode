class Solution {
public:

        int longestValidParentheses(string s) {
            int n = s.length();
            stack<pair<char,int>> st;
            st.push({'*', -1});
            
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(st.top().first == '(' && s[i] == ')')
                {
                    st.pop();
                    ans = max(ans, i - st.top().second);
                }
                else
                {
                    st.push({s[i], i});
                }
            }
            return ans;
        }
};


    
    
//     int longestValidParentheses(string s) {
//         stack<char> st;
//         int ans = 0;
//         for(auto i : s)
//         {
//             if(!st.empty() && st.top() != i)
//             {
//                 ans += 2;
//                 st.pop();
//             }
//             else
//             {
//                 st.push(i);
//             }
//         }
        
//         cout << ans << " " << st.size() << endl;
//         return ans;
//         while(!st.empty())
//         {
//             char c = st.top();
//             st.pop();
//             if(!st.empty() && st.top() != c)
//             {
//                 ans += 2;
//                 st.pop();
//             }
//         }
//         return ans;
//     }
// };