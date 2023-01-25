class Solution {
public:
    
//     Runtime: 153 ms, faster than 98.89% of C++ online submissions for Find Closest Node to Given Two Nodes.
// Memory Usage: 97.9 MB, less than 69.53% of C++ online submissions for Find Closest Node to Given Two Nodes.   
    
    
    void dfs(int node, vector<int>& edges, vector<int>& dist, vector<bool>& visit) {
        visit[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && !visit[neighbor]) {
            dist[neighbor] = 1 + dist[node];
            dfs(neighbor, edges, dist, visit);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());
        vector<bool> visit1(n), visit2(n);
        dist1[node1] = 0, dist2[node2] = 0;

        dfs(node1, edges, dist1, visit1);
        dfs(node2, edges, dist2, visit2);

        int minDistNode = -1, minDistTillNow = numeric_limits<int>::max();
        for (int currNode = 0; currNode < n; currNode++) {
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])) {
                minDistNode = currNode;
                minDistTillNow = max(dist1[currNode], dist2[currNode]);
            }
        }

        return minDistNode;
    }
};
    
    
//     void dfs(int i, vector<int> &edges, map<int,int> &mp, int count, int &ans, vector<int> vis, int mini)
//     {
//         if(vis[i])
//             return;
        
//         if(count < mini)
//         {
//             ans = 
//         }
//     }
    
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         int n = edges.size();
        
//         vector<vector<int>> v(n);
//         for(int i = 0; i < n; i++)
//         {
//             if(edges[i] != -1)
//                 v[i].push_back(edges[i]);
//         }
        
//         map<int,int> mp;
//         int count = 0;
//         int ans = -1;
//         vector<int> vis(n, 0);
//         int mini = INT_MIN;
//         dfs(node1, edges, mp, count, ans, vis, mini);
        
//         return dfs(node2, edges, mp, count, ans, mini);
        
//     }
// };