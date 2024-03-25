class Solution {
public:
    
//****####**** Never Love Anyone in Your Life -> Enjoy Coding Alone ****####****
    
        
    // without &, Time and Space complexity = 2e25 * 25 ~ xe8 * 100; -- Giving MLE
    // with & , Time and Space Complexity = 2e25 -- Accepted
    
//     Runtime: 271 ms, faster than 12.52% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 14.9 MB, less than 61.21% of C++ online submissions for Remove Invalid Parentheses.        
   
    
    // Was using the countRemovals function to remove TLE but I guess don't need this it was because of &. Let's check that.
        
    set<string> st;
    void solve(int i, int count, string &s, string &p)
    {
        int n = s.length();
        if(count == 0 && p.length() > 0)
            st.insert(p);
        if(i >= n || count < 0)
            return;
        if(s[i] == ')' || s[i] == '(')
            solve(i+1, count, s, p);
        p += s[i];
        if(s[i] == '(')
            solve(i+1, count+1, s, p);
        else if(s[i] == ')')
            solve(i+1, count-1, s, p);
        else
            solve(i+1, count, s, p);
        p.pop_back();
    }
    
    vector<string> removeInvalidParentheses(string s) {
        string p = "";
        solve(0, 0, s, p);
        vector<string> ans;
        int maxi = 0;
        for(auto i : st)
            maxi = max(maxi, (int)i.length());
        for(auto i : st)
        {
            if(i.length() == maxi)
                ans.push_back(i);
        }
        if(ans.size() == 0)
            ans.push_back("");
        return ans;
    }
};    

    
    // Learning must use "&" even in the small size string 
    
//     Runtime: 174 ms, faster than 30.33% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 12.8 MB, less than 67.06% of C++ online submissions for Remove Invalid Parentheses.
    
//     set<string> st;
    
//     int countRemovals(string &s)
//     {
//         stack<char> st;
//         for(auto i : s)
//         {
//             if(i >= 'a' && i <= 'z')
//                 continue;
//             if(i == '(')
//                 st.push(i);
//             else if(st.empty() || st.top() == ')')
//                 st.push(i);
//             else
//                 st.pop();
//         }
//         return st.size();
//     }
    
//     void solve(int i, int count, string &s, string &p, int removals)
//     {
//         int n = s.length();
//         if(count == 0 && p.length() > 0 && removals == 0)
//             st.insert(p);
//         if(i >= n || count < 0 || removals < 0)
//             return;
//         if(s[i] == ')' || s[i] == '(')
//             solve(i+1, count, s, p, removals - 1);
//         p += s[i];
//         if(s[i] == '(')
//             solve(i+1, count+1, s, p, removals);
//         else if(s[i] == ')')
//             solve(i+1, count-1, s, p, removals);
//         else
//             solve(i+1, count, s, p, removals);
//         p.pop_back();
//     }
    
//     vector<string> removeInvalidParentheses(string s) {
//         string p = "";
//         int removals = countRemovals(s);
//         // cout << s.size() << " " << removals << " " << s.size() - removals << endl;
//         solve(0, 0, s, p, removals);
//         vector<string> ans;
//         int maxi = 0;
//         for(auto i : st)
//             maxi = max(maxi, (int)i.length());
//         for(auto i : st)
//         {
//             if(i.length() == maxi)
//                 ans.push_back(i);
//         }
//         if(ans.size() == 0)
//             ans.push_back("");
//         return ans;
//     }
// };