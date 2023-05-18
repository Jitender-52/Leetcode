class Solution {
public:
    
//     Runtime: 326 ms, faster than 58.94% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.
// Memory Usage: 94.3 MB, less than 84.26% of C++ online submissions for Minimum Number of Vertices to Reach All Nodes.

    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, 0);
        for(auto &i : edges)
        {
            incoming[i[1]] = 1;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(!incoming[i])
                ans.push_back(i);
        }
        return ans;
    }
};