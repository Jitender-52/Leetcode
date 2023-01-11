class Solution {
public:
    
    int dfs(int node, int parent, vector<vector<int>> &v, vector<bool> &hasApple)
    {
        int totalTime = 0;
        int childTime = 0;
        
        for(auto child : v[node])
        {
            if(child == parent)
                continue;
            childTime = dfs(child, node, v, hasApple);
            
            if(childTime || hasApple[child])
                totalTime += childTime + 2;
        }
        return totalTime;
    }
    
    int minTime(int n, vector<vector<int>>& edge, vector<bool>& hasApple) {
        
        vector<vector<int>> v(n);
        int p = edge.size();
        
        for(int i = 0; i < p; i++)
        {
            v[edge[i][0]].push_back(edge[i][1]);
            v[edge[i][1]].push_back(edge[i][0]);
        }
            
        return dfs(0, -1, v, hasApple);
    }
};