class Solution {
public:
    
    map<int, set<int>> adj;
    vector<int> ans;
    
    void dfs(int node, int parent)
    {
        ans.push_back(node);
        for(auto i : adj[node])
        {
            if(i != parent)
                dfs(i, node);
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for(auto i : adjacentPairs)
        {
            adj[i[0]].insert(i[1]);
            adj[i[1]].insert(i[0]);
        }
        
        int start = 0;
        for(auto i : adj)
        {
            if(i.second.size() == 1)
            {
                start = i.first;
                break;
            }
        }
        dfs(start, start);
        return ans;
    }
};