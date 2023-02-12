class Solution {
public:
        
        int dfs(int i, long long &ans, vector<int> &vis, map<int,list<int>> &adj, int &seats)
        {
            int count = 1;
            vis[i] = 1;
            for(auto j : adj[i])
            {
                if(!vis[j])
                {
                    count += dfs(j, ans, vis, adj, seats);
                }
            }
            
            if(i != 0)
            {
                ans += ceil(double(count) / seats);
            }
            return count;
        }
    
        long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
            int n = roads.size();
            
            map<int,list<int>> adj;
            
            vector<int> vis(n+2, 0);
            for(int i = 0; i < n; i++)
            {
                adj[roads[i][0]].push_back(roads[i][1]);
                adj[roads[i][1]].push_back(roads[i][0]);
            }
            
            long long ans = 0;
            
            dfs(0, ans, vis, adj, seats);
            return ans;
        }
};
    
    
//     int dfs(int i, map<int, list<int>> &adj, vector<int> &vis)
//     {
//         vis[i] = true;
//         int ans = 0;
//         for(auto j : adj[i])
//         {
//             if(!vis[j])
//             {
//                 ans += 1 + dfs(j, adj, vis);
//             }
//         }
//         return ans;
//     }
    
//     int apSum(int nth, int d)
//     {
//         int n = ceil(double(nth) / d);
//         // return n;
//         int a = nth - (n-1) * (-d);
        
//         int ans = (n * (2*nth + ((n-1)*(-d)))) / 2;
//         return ans;
//     }
    
//     long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
//         int n = roads.size();
//         map<int, list<int>> adj;
        
//         for(int i = 0; i < n; i++)
//         {
//             adj[roads[i][0]].push_back(roads[i][1]);
//             adj[roads[i][1]].push_back(roads[i][0]);
//         }
        
//         vector<int> vis(n+2, 0);
        
//         int ans = 0;
//         vis[0] = true;
//         for(auto i : adj[0])
//         {
//             // vis[i] = true;
//             int count = 1 + dfs(i, adj, vis);
//             cout << i << " " << count << endl;
//             ans += apSum(count, seats);
//             // cout << ans << endl;
//         }
//         // cout << endl;
//         return ans;
//     }
// };