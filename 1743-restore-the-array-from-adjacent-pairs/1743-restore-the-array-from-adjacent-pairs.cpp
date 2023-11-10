class Solution {
public:
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> adj;
        for(auto i : adjacentPairs)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> ans;
        for(auto i : adj)
        {
            if(i.second.size() == 1)
            {
                ans.push_back(i.first);
                ans.push_back(i.second[0]);
                break;
            }
        }
        
        while(adj[ans[ans.size()-1]].size() != 1)
        {
            int last = ans[ans.size() - 1];
            int prev = ans[ans.size() - 2];
            for(auto i : adj[last])
            {
                if(i != prev)
                {
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
    
    
//     Runtime: 690 ms, faster than 11.52% of C++ online submissions for Restore the Array From Adjacent Pairs.
// Memory Usage: 179.9 MB, less than 5.15% of C++ online submissions for Restore the Array From Adjacent Pairs.    
    
//     map<int, set<int>> adj;
//     vector<int> ans;
    
//     void dfs(int node, int parent)
//     {
//         ans.push_back(node);
//         for(auto i : adj[node])
//         {
//             if(i != parent)
//                 dfs(i, node);
//         }
//     }
    
//     vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
//         for(auto i : adjacentPairs)
//         {
//             adj[i[0]].insert(i[1]);
//             adj[i[1]].insert(i[0]);
//         }
        
//         int start = 0;
//         for(auto i : adj)
//         {
//             if(i.second.size() == 1)
//             {
//                 start = i.first;
//                 break;
//             }
//         }
//         dfs(start, start);
//         return ans;
//     }
// };