class Solution {
public:
    
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int n = coordinates.size();
        map<pair<int,int>, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[{coordinates[i][0], coordinates[i][1]}]++;
        }
        
        long long ans = 0;
        
        if(k == 0)
        {
            for(int i = 0; i < n; i++)
            {
                ans += mp[{coordinates[i][0], coordinates[i][1]}] - 1;
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j <= k; j++)
                {
                    int a = j, b = k-a;
                    int x = a ^ coordinates[i][0], y = b ^ coordinates[i][1];
                    // cout << x << " " << y << endl;
                    ans += mp[{x, y}];
                }
            }
        }
        return ans / 2;
    }
};
    
    
//     int countPairs(vector<vector<int>>& coordinates, int k) {
//         int n = coordinates.size();
        
//         // vector<vector<int>>  v;
//           // map<int,int> mp;
       
// //         for(auto i : coordinates)
// //         {
// //             if(i[0] < k && i[1] < k)
// //             {
                
// //             }
// //         }
        
//           map<int,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             // ans += mp[coordinats[i][0] ^ coordinates[i][1]];
//             mp[coordinates[i][0] ^ coordinates[i][1]]++;
//         }
        
      
//         int ans = 0, count = 0;
//         if(n >= 1e3)
//         {
//             // for(auto i : mp)
//             // {
//             //     // cout << i.first << " " << i.second << endl;
//             //     int a = i.first;
//             //     int b = (i.first ^ k);
//             //     cout << a << " " << b << "  " << mp[a] <<" " << mp[b] << endl;
//             //     if(a == b)
//             //     {
//             //         int x = mp[a];
//             //         count += (x * (x-1)) / 2;
//             //     }
//             //     else
//             //     {
//             //         ans += mp[a] * mp[b];
//             //         // mp[b] = 0;
//             //     }
//             // }
//             // return ((ans/2) + count);

//             for(auto i : mp)
//             {
//                 for(auto j : mp)
//                 {
//                     if((i.first ^ j.first) == k)
//                     {
//                         if(i.first == j.first)
//                         {
//                             count += (i.second * (i.second-1)) / 2;
//                         }
//                         else
//                         {
//                             ans += i.second * j.second;
//                         }
//                     }
//                 }
//             }
//         }
//         else
//         {
//             vector<vector<int>> v = coordinates;
//             for(int i = 0; i < n; i++)
//             {
//                 for(int j = i + 1; j < n; j++)
//                 {
//                     int a = (v[i][0] ^ v[j][0]);
//                     int b = (v[i][1] ^ v[j][1]);
//                     // cout << a <<" " << b << endl;
//                     if(a + b == k)
//                     {
//                         // cout << i + 1 << " " << j + 1 << endl;
//                         ans++;
//                     }
//                 }
//             }
//         }
        
//         // for(int i = 0; i < n; i++)
//         // {
//         //     ans += mp[coordinates[i][0] ^ coordinates[i][1]];
//         //     mp[((coordinates[i][0] ^ coordinates[i][1]) ^ k)]++;
//         // }
        
//         return ans;
// //         return (count + (ans / 2));        
//     }
// };