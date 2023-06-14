class Solution {
public:
    
    bool cycle(int src, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &graph)
    {
        vis[src] = 1;
        dfsVis[src] = 1;
        for(auto it : graph[src])
        {
            if(dfsVis[it])
                return true;
            else if(!vis[it] && cycle(it, vis, dfsVis, graph))
                return true;
        }
        dfsVis[src] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n), dfsVis(n);
        // for(int i = 0; i < n; i++)
        // {
        //     vector<int> v;
        //     if(!vis[i] && !cycle(i, vis, dfsVis, graph, v))
        //     {
        //         for(auto &it : v) 
        //         {
        //             ans.push_back(it);
        //         }
        //     }
        // }
        
        for(int i = 0; i < n; i++)
        {
            cycle(i, vis, dfsVis, graph);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(!dfsVis[i])
                ans.push_back(i);
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};