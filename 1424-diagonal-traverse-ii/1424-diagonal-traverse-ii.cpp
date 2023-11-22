class Solution {
public:
    
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        queue<pair<int,int>> q;
        q.push({0, 0});
        vector<int> ans;
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans.push_back(nums[row][col]);
            if(col == 0 && row + 1 < n)
                q.push({row+1, col});
            if(col + 1 < nums[row].size())
                q.push({row, col+1});
        }
        return ans;
    }
};
    
//     Runtime: 224 ms, faster than 39.10% of C++ online submissions for Diagonal Traverse II.
// Memory Usage: 99.2 MB, less than 35.68% of C++ online submissions for Diagonal Traverse II.

    
//     vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
//         map<int, vector<int>> mp;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             for(int j = 0; j < nums[i].size(); j++)
//                 mp[i + j].push_back(nums[i][j]);
//         }
//         vector<int> ans;
//         for(auto &[it, v] : mp)
//         {
//             for(int i = v.size()-1; i >= 0; i--)
//                 ans.push_back(v[i]);
//         }
//         return ans;
//     }
// };