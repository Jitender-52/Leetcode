class Solution {
public:
    
//     Runtime: 165 ms, faster than 81.35% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 47.8 MB, less than 79.00% of C++ online submissions for Find Eventual Safe States.
    
        bool cycle(int src, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &graph)
        {
            dfsVis[src] = 1;
            vis[src] = 1;
            for(auto it : graph[src])
            {
                if(dfsVis[it])
                    return true;
                if(!vis[it] && cycle(it, vis, dfsVis, graph))
                    return true;
            }
            dfsVis[src] = 0;
            return false;
        }
    
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            vector<int> ans, vis(n, 0), dfsVis(n, 0);
            
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
    
    
//     Runtime: 176 ms, faster than 61.87% of C++ online submissions for Find Eventual Safe States.
// Memory Usage: 47.8 MB, less than 77.56% of C++ online submissions for Find Eventual Safe States.
    
//     bool cycle(int src, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &graph)
//     {
//         vis[src] = 1;
//         dfsVis[src] = 1;
//         for(auto it : graph[src])
//         {
//             if(dfsVis[it])
//                 return true;
//             else if(!vis[it] && cycle(it, vis, dfsVis, graph))
//                 return true;
//         }
//         dfsVis[src] = 0;
//         return false;
//     }
    
//     vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//         int n = graph.size();
//         vector<int> ans;
//         vector<int> vis(n), dfsVis(n);
//         // for(int i = 0; i < n; i++)
//         // {
//         //     vector<int> v;
//         //     if(!vis[i] && !cycle(i, vis, dfsVis, graph, v))
//         //     {
//         //         for(auto &it : v) 
//         //         {
//         //             ans.push_back(it);
//         //         }
//         //     }
//         // }
        
//         for(int i = 0; i < n; i++)
//         {
//             cycle(i, vis, dfsVis, graph);
//         }
        
//         for(int i = 0; i < n; i++)
//         {
//             if(!dfsVis[i])
//                 ans.push_back(i);
//         }
        
//         sort(ans.begin(), ans.end());
//         return ans;
//     }
// };