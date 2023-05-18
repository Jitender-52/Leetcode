class Solution {
public:
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