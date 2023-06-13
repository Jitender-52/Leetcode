class Solution {
public:
    
        int equalPairs(vector<vector<int>>& grid) {       
            int n = grid.size();
            map<vector<int>, int> mp;
            for(int i = 0; i < n; i++)
            {
                mp[grid[i]]++;
            }
            
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                vector<int> v;
                for(int j = 0; j < n; j++)
                {
                    v.push_back(grid[j][i]);
                }
                ans += mp[v];
            }
            return ans;
        }
};
    
    
    
//     Runtime: 137 ms, faster than 72.74% of C++ online submissions for Equal Row and Column Pairs.
// Memory Usage: 39.3 MB, less than 24.18% of C++ online submissions for Equal Row and Column Pairs.
    
    
//     int nc2(int n)
//     {
//         return (n * (n-1))/2;
//     }
    
//     int equalPairs(vector<vector<int>>& grid) {       
//         int n = grid.size();
//         map<vector<int>, int> mp;
//         int count = 0;
        
//         for(int i = 0; i < n; i++)
//         {
//             mp[grid[i]]++;
//         }
//         for(int i = 0; i < n; i++)
//         {
//             vector<int> v;
//             for(int j = 0; j < n; j++)
//             {
//                 v.push_back(grid[j][i]);
//             }
//             count += mp[v];
//         }
        
//         // int count = 0;
//         // for(auto i : mp)
//         // {
//         //     if(i.second > 1)
//         //     {
//         //         count += nc2(i.second);
//         //     }
//         // }
//         return count;
//     }
// };