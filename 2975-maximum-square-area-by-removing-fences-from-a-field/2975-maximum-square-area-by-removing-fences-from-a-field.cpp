class Solution {
public:
    
    const int mod = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        long long ans = -1;
        set<int> st;
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        for(int i = 0; i < h.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                st.insert(h[i] - h[j]);
            }
        }
        for(int i = 0; i < v.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(st.find(v[i] - v[j]) != st.end())
                    ans = max(ans, (v[i] - v[j]) * 1LL * (v[i] - v[j]));
            }
        }
        return ans == -1 ? -1 : ans % mod;
    }
};
    
//     int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
//         int sz1 = h.size(), sz2 = v.size();
//         sort(h.begin(), h.end());
//         sort(v.begin(), v.end());
        
//         int ans = -1;
//         if(m == n)
//             ans = max(ans, (m-1) * (n-1));
//         for(int i = 0; i < sz1; i++)
//         {
//             int a = (n - 1) * 1LL * (n-1);
//             if(m - h[i] == n-1)
//                 ans = max(ans, a);
//                 // ans = max(ans, (n - 1) * (n - 1));
//             if(h[i] == n)
//                 ans = max(ans, a);
//                 // ans = max(ans, (n - 1) *  (n - 1));    
//         }
        
//         for(int i = 0; i < sz2; i++)
//         {
//             int a = (m - 1) * 1LL * (m-1);
//             if(n - v[i] == m-1)
//                 ans = max(ans, a);
//                 // ans = max(ans, (n - 1) * (n - 1));
//             if(v[i] == m)
//                 ans = max(ans, a);
//                 // ans = max(ans, (n - 1) *  (n - 1));    
//         }
        
//         for(int i = 0; i < sz1; i++)
//         {
//             for(int j = 0; j < sz2; j++)
//             {
//                 if(h[i] == v[j])
//                     ans = max(ans, h[i] * v[i]);
//                 if(m - h[i] == n - 1)
//                     ans = max(ans, (n - 1) * (n - 1));
//                 if(n - v[j] == m-1)
//                     ans = max(ans, (m-1) * (m-1));
//                 if(n - v[j] == m-h[i])
//                     ans = max(ans, (n - v[j]) * (n - v[j]));
//             }
//         }
        
//         // map<int,int> mp1, mp2;
//         // for(int i = 0; i < sz1; i++)
//         // {
//         //     mp1[h[i]]++;
//         // }
//         // for(int i = 0; i < sz2; i++)
//         // {
//         //     mp2[v[i]]++;
//         // }
// //         mp1[m-1]++;
// //         mp2[n-1]++;
// //         int count = 0;
// //         for(int i = 1; i <= min(m, n); i++)
// //         {
// //             if(mp1.find(i) != mp1.end() && mp2.find(i) != mp2.end())
// //                 count = i;
// //             else
// //                 count = 0;
// //             // cout << i << " " << count << endl;
            
// // //             if(i == n && mp1.find(i) != mp1.end())
// // //                 ans = max(ans, i * 1LL * i);
// // //             if(i == m && mp2.find(i) != mp2.end())
// // //                 ans = max(ans, i * 1LL * i);
            
// //             if(count > 0)
// //                 ans = max(ans, (count-1) * (count-1));
// //         }
        
//         if(ans == -1)
//             return ans;
//         ans = ans % mod;
//         return ans;
        
//     }
// };
    
//     int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
//         int sz1 = h.size(), sz2 = v.size();
        
//         if(m == n)
//         {
//             int ans = 0;
//             m--;
//             n--;
//             ans = m * 1LL * n;
//             ans %= mod;
//             return ans;
//         }
        
        
        
//         map<int,int> mp1, mp2;
//         for(int i = 0; i < sz1; i++)
//         {
//             mp1[h[i]]++;
//         }
//         for(int i = 0; i < sz2; i++)
//         {
//             mp2[v[i]]++;
//         }
//         // mp1[m-1]++;
//         // mp2[n-1]++;
//         int ans = -1, count = 0;
//         for(int i = 1; i <= min(m, n); i++)
//         {
//             if(mp1.find(i) != mp1.end() && mp2.find(i) != mp2.end())
//                 count = i;
//             else
//                 count = 0;
//             // cout << i << " " << count << endl;
            
//             if(i == n && mp1.find(i) != mp1.end())
//                 ans = max(ans, i * 1LL * i);
//             if(i == m && mp2.find(i) != mp2.end())
//                 ans = max(ans, i * 1LL * i);
            
//             if(count > 0)
//                 ans = max(ans, (count) * (count));
//         }
        
//         if(ans == -1)
//             return ans;
//         ans %= mod;
//         return ans;
//     }
// };