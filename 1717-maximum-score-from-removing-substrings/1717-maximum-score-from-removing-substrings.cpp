class Solution {
public:
    
    int maximumGain(string s, int x, int y) {
        vector<char> v, v1;
        int ans = 0;
        // First pass to remove the optimal substring
        for (auto a : s) {
            if (!v.empty()) {
                if (x > y) {
                    if (v.back() == 'a' && a == 'b') {
                        ans += x;
                        v.pop_back();
                    } else
                        v.push_back(a);
                } else {
                    if (v.back() == 'b' && a == 'a') {
                        ans += y;
                        v.pop_back();
                    } else
                        v.push_back(a);
                }
            } else {
                v.push_back(a);
            }
        }
        
         for (auto a : v)
            if (!v1.empty()) {
                if (x < y) {
                    if (v1.back() == 'a' && a == 'b') {
                        ans += x;
                        v1.pop_back();
                    } else
                        v1.push_back(a);
                } else {
                    if (v1.back() == 'b' && a == 'a') {
                        ans += y;
                        v1.pop_back();
                    } else
                        v1.push_back(a);
                }
            } else {
                v1.push_back(a);
            }
        
        return ans;
    }
};
    
    
//     int maximumGain(string s, int x, int y) {
//         int ans = 0;
//         stack<char> st;
//         if(x > y)
//         {
//             for(auto i : s)
//             {
//                 if(i == 'b')
//                 {
//                     if(!st.empty() && st.top() == 'a')
//                     {
//                         ans += x;
//                         st.pop();
//                     }
//                     else
//                         st.push(i);
//                 }
//                 else
//                     st.push(i);
//             }
//         }
//         else
//         {
//             for(auto i : s)
//             {
//                 if(i == 'a')
//                 {
//                     if(!st.empty() && st.top() == 'b')
//                     {
//                         ans += y;
//                         st.pop();
//                     }
//                     else
//                         st.push(i);
//                 }
//                 else
//                     st.push(i);
//             }
//         }
        
//         s = "";
//         while(!st.empty())
//         {
//             s += st.top();
//             st.pop();
//         }
//         reverse(s.begin(), s.end());
        
//         // Second time 
//         if(x > y)
//         {
//             for(auto i : s)
//             {
//                 if(i == 'b')
//                 {
//                     if(!st.empty() && st.top() == 'a')
//                     {
//                         ans += x;
//                         st.pop();
//                     }
//                     else
//                         st.push(i);
//                 }
//                 else
//                     st.push(i);
//             }
//         }
//         else
//         {
//             for(auto i : s)
//             {
//                 if(i == 'a')
//                 {
//                     if(!st.empty() && st.top() == 'b')
//                     {
//                         ans += y;
//                         st.pop();
//                     }
//                     else
//                         st.push(i);
//                 }
//                 else
//                     st.push(i);
//             }
//         }
        
//         // return ans;
        
//         while(st.size() > 1)
//         {
//             char a = st.top();
//             st.pop();
//             char b = st.top();
//             st.pop();
//             if(a == 'b' && b == 'a')
//                 ans += x;
//             else if(a == 'a' && b == 'b')
//                 ans += y;
//             else
//                 st.push(b);
//         }
//         return ans;
        
//     }
// };