
// Runtime: 727 ms, faster than 21.18% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.
// Memory Usage: 269.5 MB, less than 100.00% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.

const int MAX = 1e5 + 2;
vector<int> adj[MAX];
vector<int> dist(MAX, 0);

class Solution {
public:
    
//     Runtime: 1070 ms, faster than 50.00% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.
// Memory Usage: 268.6 MB, less than 100.00% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.
    
    int dfs(int node, int parent, int d, int i)
    {
        dist[node] = max(dist[node], d);
        int farthestNode_tillNow = -1;
        for (auto neighbour : adj[node])
        {
            if (neighbour != parent)
            {
                int x = dfs(neighbour, node, d + 1, i);
                if (farthestNode_tillNow == -1 || dist[x] > dist[farthestNode_tillNow])
                {
                    farthestNode_tillNow = x;
                }
            }
        }
        if (farthestNode_tillNow == -1)
            return node;
        return farthestNode_tillNow;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
        // ********************** For Tree 1  **********************
        for(int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        dist.clear();
        dist.resize(MAX, 0);
        for (auto i : edges1)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int farthestNode = dfs(1, -1, 0, 0);
        int farthestNode2 = dfs(farthestNode, -1, 0, 0);
        dfs(farthestNode2, -1, 0, 1);                   
        int d1 = *max_element(dist.begin(), dist.end());
        
        
        // ********************** For Tree 2  **********************
        for(int i = 0; i < MAX; i++)
        {
            adj[i].clear();
        }
        dist.clear();
        dist.resize(MAX, 0);
        for (auto i : edges2)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        farthestNode = dfs(1, -1, 0, 0);
        farthestNode2 = dfs(farthestNode, -1, 0, 0);
        dfs(farthestNode2, -1, 0, 1);                   
        int d2 = *max_element(dist.begin(), dist.end());
        
        return max({(d1 + 1) / 2 + (d2 + 1) / 2 + 1, d1, d2});
    }
};
    
    
//     Runtime: 1080 ms, faster than 50.00% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.
// Memory Usage: 268.6 MB, less than 100.00% of C++ online submissions for Find Minimum Diameter After Merging Two Trees.
    
//     int dfs(int node, int parent, int d, int i)
//     {
//         // dist[node][i] = d;
//         dist[node] = max(dist[node], d);
//         int farthestNode_tillNow = -1;
//         for (auto neighbour : adj[node])
//         {
//             if (neighbour != parent)
//             {
//                 int x = dfs(neighbour, node, d + 1, i);
//                 if (farthestNode_tillNow == -1 || dist[x] > dist[farthestNode_tillNow])
//                 {
//                     farthestNode_tillNow = x;
//                 }
//             }
//         }
//         if (farthestNode_tillNow == -1) // when we reach at the end of dfs at a time, when there is no unvisited neighbour of node
//             return node;
//         return farthestNode_tillNow;
//     }
    
//     int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        
//         // ********************** For Tree 1  **********************
//         for(int i = 0; i < MAX; i++)
//         {
//             adj[i].clear();
//         }
//         dist.clear();
//         dist.resize(MAX, 0);
//         for (auto i : edges1)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         int farthestNode = dfs(1, -1, 0, 0);
//         int farthestNode2 = dfs(farthestNode, -1, 0, 0);
//         dfs(farthestNode2, -1, 0, 1);                   
//         // cout << farthestNode << " " << farthestNode2 << endl; // Two end nodes of the diameter;
//         int d1 = *max_element(dist.begin(), dist.end());
        
        
//         // ********************** For Tree 2  **********************
//         for(int i = 0; i < MAX; i++)
//         {
//             adj[i].clear();
//         }
//         dist.clear();
//         dist.resize(MAX, 0);
//         for (auto i : edges2)
//         {
//             adj[i[0]].push_back(i[1]);
//             adj[i[1]].push_back(i[0]);
//         }
//         farthestNode = dfs(1, -1, 0, 0);
//         farthestNode2 = dfs(farthestNode, -1, 0, 0);
//         dfs(farthestNode2, -1, 0, 1);                   
//         // cout << farthestNode << " " << farthestNode2 << endl; // Two end nodes of the diameter;
//         int d2 = *max_element(dist.begin(), dist.end());
        
// //         cout << d1 << " " << d2 << endl;
// //         cout << endl;
//         return max({(d1 + 1) / 2 + (d2 + 1) / 2 + 1, d1, d2});
//     }
// };