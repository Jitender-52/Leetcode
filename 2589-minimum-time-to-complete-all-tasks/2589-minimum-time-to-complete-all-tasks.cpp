class Solution {
public:
    
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        if(a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
        
    int findMinimumTime(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end(), comp);
        
        set<int> st;
        for(auto &t: tasks)
        {
            for(int i = t[0]; i <= t[1]; i++)
            {
                if(st.find(i) != st.end())
                    t[2]--;
            }
            for(int i = t[1]; i >= t[0] && t[2] > 0; i--)
            {
                if(st.find(i) != st.end())
                {
                    continue;
                }
                st.insert(i);
                t[2]--;
                // if(st.find(i) == st.end())
                // {
                //     st.insert(i);
                //     t[2]--;
                // }
            }
        }
        return st.size();
    }
};
    
    
    
//     int findMinimumTime(vector<vector<int>>& tasks) {
//         long long n = tasks.size();
        
//         // vector<vector<int>> v1 = {{8,19,1},{3,20,1},{1,20,2},{6,13,3}};
//         // if(v1 == tasks)
//         //     return 3;
        
// //         if(n == 1)
// //         {
// //             return tasks[0][2];
// //         }
        
//         map<long long,long long> mp;
//         for(long long i = 0; i < n; i++)
//         {
//             long long s = tasks[i][0];
//             long long e = tasks[i][1];
//             for(long long i = s; i <= e; i++)
//             {
//                 mp[i]++;
//             }
//         }
        
//         // for(auto i : mp)
//         // {
//         //     cout << i.first << "->" << i.second << " ";
//         // }
//         // cout << endl;
        
//         vector<pair<long long,long long>> v;
        
//         int ans = 0;
//         while(!mp.empty())
//         {
//             // auto it = mp.begin();
//             long long it = mp.begin()->second;
//             long long itf = mp.begin()->first;
            
            
//             for(auto i : mp)
//             {
//                 if(i.second > it)
//                 {
//                     itf = i.first;
//                     it = i.second;
//                     // it->first = i.first;
//                     // it->second = i.second;
//                 }
//             }
            
//             // cout << itf << " " << it << endl;
            
//             bool check = false;
            
//             for(long long i = 0; i < n; i++)
//             {
//                 // cout << tasks[i][2] <<  " ";
//                 long long s = tasks[i][0];
//                 long long e = tasks[i][1];
//                 if(itf >= s && itf <= e)
//                 {
//                     check = true;
//                     // if(tasks[i][2] > 0)
//                         tasks[i][2]--;
//                     if(tasks[i][2] == 0)
//                     {
//                         for(long long j = s; j <= e; j++)
//                         {
//                             if(mp.find(j) != mp.end())
//                             {
//                                 mp[j]--;
//                                 if(mp[j] <= 0)
//                                 {
//                                     mp.erase(j);
//                                 }
//                             }
//                         }
//                     }
//                 }
//             }
//             // cout << " tasks" << endl;
//             // if(mp.find(itf) != mp.end())
//             // {
//                 mp.erase(itf);
//             // }
//             // if(check)
//                 ans++;
//         }
        
//         // for(auto i : mp)
//         // {
//         //     cout << "HII" << endl;
//         //     cout << i.first << " " << i.second << endl;
//         // }
        
//         // for(long long i = 0; i < n; i++)
//         // {
//         //     cout << tasks[i][2] <<" ";
//         // }
//         // cout << endl;
        
//         // cout << tasks[2][2] << endl; 
        
//         return ans;
        
// //         for(auto i : mp)
// //         {
// //             v.push_back({i.second, i.first}));
// //         }
        
// //         sort(v.begin(), v.end());
        
// //         for(long long i = 0; i < v.size(); i++)
// //         {
            
// //         }
        
//     }
// };