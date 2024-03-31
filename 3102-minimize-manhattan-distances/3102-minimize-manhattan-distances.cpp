class Solution
{
public:
    
    int minimumDistance(vector<vector<int>> &points)
    {
        int n = points.size();
        multiset<int> st1, st2;
        for(int i = 0; i < n; i++)
        {
            st1.insert(points[i][0] + points[i][1]);
            st2.insert(points[i][0] - points[i][1]);
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++)
        {
            st1.erase(st1.find(points[i][0] + points[i][1]));
            st2.erase(st2.find(points[i][0] - points[i][1]));
            ans = min(ans, max(*prev(st1.end()) - *st1.begin(), *prev(st2.end()) - *st2.begin()));
            st1.insert(points[i][0] + points[i][1]);
            st2.insert(points[i][0] - points[i][1]);
        }
        return ans;
    }
};
    
    
//     Runtime: 1044 ms, faster than 16.67% of C++ online submissions for Minimize Manhattan Distances.
// Memory Usage: 225.2 MB, less than 33.33% of C++ online submissions for Minimize Manhattan Distances.
    
//     int minimumDistance(vector<vector<int>> &points)
//     {
//         int n = points.size();
//         multiset<int> st1, st2;
//         for(int i = 0; i < n; i++)
//         {
//             st1.insert(points[i][0] + points[i][1]);
//             st2.insert(points[i][0] - points[i][1]);
//         }
//         int ans = 1e9;
//         for(int i = 0; i < n; i++)
//         {
//             st1.erase(st1.find(points[i][0] + points[i][1]));
//             st2.erase(st2.find(points[i][0] - points[i][1]));
//             ans = min(ans, max(*st1.rbegin() - *st1.begin(), *st2.rbegin() - *st2.begin()));
//             st1.insert(points[i][0] + points[i][1]);
//             st2.insert(points[i][0] - points[i][1]);
//         }
//         return ans;
//     }
// };
    
    
//     int solve(vector<pair<int, int>> &points)
//     {
//         int n = points.size();
//         int mini1 = 0, maxi1 = 0, mini2 = 0, maxi2 = 0;

//         mini1 = maxi1 = points[0].first + points[0].second;
//         mini2 = maxi2 = points[0].first - points[0].second;
//         for (int i = 1; i < n; i++)
//         {
//             int total = points[i].first + points[i].second;
//             int x = points[i].first - points[i].second;
//             if (total < mini1)
//                 mini1 = total;
//             else if (total > maxi1)
//                 maxi1 = total;
//             if (x < mini2)
//                 mini2 = x;
//             else if (x > maxi2)
//                 maxi2 = x;
//         }
//         return max(maxi1 - mini1, maxi2 - mini2);
//     }

//     int minimumDistance(vector<vector<int>> &v)
//     {
//         int n = v.size();
//         // vector<pair<int, int>> points;
        
//         vector<int> a, b;
//         for(int i = 0; i < n; i++)
//         {
//             a.push_back(v[i][0]);
//             b.push_back(v[i][1]);
//         }
//         sort(a.begin(), a.end());
//         sort(b.begin(), b.end());
        
//         map<int, vector<int>> mp1, mp2;
//         for(auto i : v)
//         {
//             mp1[i[0]].push_back(i[1]);
//         }
//         for(auto i : v)
//         {
//             mp2[i[1]].push_back(i[0]);
//         }
        
//         set<pair<int,int>> st;
//         st.insert({a[0], mp1[a[0]][0]});
//         st.insert({a[0], mp1[a[0]].back()});
//         st.insert({a[1], mp1[a[1]][0]});
//         st.insert({a[1], mp1[a[1]].back()});
        
//         st.insert({a[n-1], mp1[a[n-1]][0]});
//         st.insert({a[n-1], mp1[a[n-1]].back()});
//         st.insert({a[n-2], mp1[a[n-2]][0]});
//         st.insert({a[n-2], mp1[a[n-2]].back()});
        
//         int j = 0;
//         st.insert({mp2[b[j]][0], b[j]});
//         st.insert({mp2[b[j]].back(), b[j]});
//         j = 1;
//         st.insert({mp2[b[j]][0], b[j]});
//         st.insert({mp2[b[j]].back(), b[j]});

//         j = n-1;
//         st.insert({mp2[b[j]][0], b[j]});
//         st.insert({mp2[b[j]].back(), b[j]});
//         j = n-2;
//         st.insert({mp2[b[j]][0], b[j]});
//         st.insert({mp2[b[j]].back(), b[j]});

//         vector<pair<int, int>> points;
//         for(auto i : st)
//             points.push_back(i);
        
//         // for (int i = 0; i < n; i++)
//         // {
//         //     points.push_back({v[i][0], v[i][1]});
//         // }

        
        
//         int ans = 1e9;
//         for (int i = 0; i < points.size(); i++)
//         {
//             vector<pair<int, int>> v1;
//             for (int j = 0; j < points.size(); j++)
//             {
//                 if (i != j)
//                     v1.push_back(points[j]);
//             }
//             // cout << points.size() << " " << v1.size() << endl;
//             if(v1.size() == 0)
//                 ans = 0;
//             else
//                 ans = min(ans, solve(v1));
//         }
//         // cout << endl;
//         return ans;
        
        
// //                 int maxi1 = 0, maxi2 = 0;
// //                 int mini1 = 1e9, mini2 = 1e9;
// //                 for(int i = 0; i < n; i++)
// //                 {
// //                     maxi1 = max(maxi1, points[i].first);
// //                     maxi2 = max(maxi2, points[i].second);
// //                     mini1 = max(mini1, points[i].first);
// //                     mini2 = max(mini2, points[i].second);
// //                 }

// //                 if(maxi1 - mini1 < maxi2 - mini2)
// //                 {
// //                     sort(points.begin(), points.end(), [&](pair<int, int> &a, pair<int, int> &b){
// //                         if(a.second == b.second)
// //                             return a.first > b.first;
// //                         return a.second < b.second;
// //                     });
// //                 }
// //                 else
// //                 {
// //                     sort(points.begin(), points.end(), [&](pair<int, int> &a, pair<int, int> &b)
// //                     {
// //                         if(a.first == b.first)
// //                             return a.second > b.second;
// //                         return a.first < b.first;
// //                     });
// //                 }

// //                 // for(int i = 0; i < n; i++)
// //                 // {
// //                 //     cout << points[i].first << " " << points[i].second << endl;
// //                 // }
// //                 // cout << endl;
        
// //             vector<int> p = {0,1,n-2,n-1};
        
// //         int ans = 1e9;
// //         for(auto i : p)
// //         {
// //             vector<pair<int,int>> v1;
// //             for(int j = 0; j < n; j++)
// //             {
// //                 if(i != j)
// //                 {
// //                     v1.push_back(points[j]);
// //                 }
// //             }
// //             ans = min(ans, solve(v1));
// //         }
// //         return ans;

//                 // return min(abs(points[n-1].first - points[1].first) + abs(points[n-1].second - points[1].second), abs(points[n-2].first - points[0].first) + abs(points[n-2].second - points[1].second));
//     }
// };