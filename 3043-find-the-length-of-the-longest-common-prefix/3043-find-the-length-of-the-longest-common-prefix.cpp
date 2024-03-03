class Solution {
public:
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for(auto i : arr1)
        {
            string s = to_string(i);
            string x = "";
            for(auto j : s)
            {
                x += j;
                st.insert(x);
            }
        }
        int ans = 0;
        for(auto i : arr2)
        {
            string s = to_string(i);
            string x = "";
            for(auto j : s)
            {
                x += j;
                if(st.find(x) != st.end())
                    ans = max(ans, (int)x.length());
            }
        }
        return ans;
    }
};
    
//     int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//         int ans = 0;
//         for(auto x : arr1)
//         {
//             for(auto y : arr2)
//             {
//                 int count = 0;
//                 string s = to_string(x), t = to_string(y);
//                 for(int i = 0; i < s.length(), i < t.length(); i++)
//                 {
//                     if(s[i] != t[i])
//                         break;
//                     count++;
//                 }
//                 ans = max(ans, count);
//             }
//         }
//         return ans;
//     }
// };