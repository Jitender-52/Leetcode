//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<vector<vector<int>>> adj(n);
        for(auto i : flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }

        vector<int> cost(n, 1e9);
        queue<pair<int,int>> q;
        q.push({0, src});
        cost[src] = 0;
        k++; // because we need to count the stops starting will not be counted as a stop
        while(k-- && !q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto c = q.front().first;
                auto node = q.front().second;
                q.pop();
                for(auto i : adj[node])
                {
                    int nnode = i[0];
                    int wt = i[1];
                    if(c + wt < cost[nnode])
                    {
                        cost[nnode] = c + wt;
                        q.push({c + wt, nnode});
                    }
                }
            }
        }
        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends