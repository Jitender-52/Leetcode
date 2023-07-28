//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	
	
    pair<int, vector<vector<int>>> minimumSpanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, -1});
        vector<int> vis(n, 0);
    
        vector<vector<int>> mst;
        int sum = 0;
    
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            auto wt = v[0], node = v[1], parent = v[2];
            if (!vis[node])
            {
                vis[node] = 1;
                if (parent != -1)
                {
                    mst.push_back({parent, node});
                }
                sum += wt;
                for (auto i : adj[node])
                {
                    if (!vis[i[0]])
                        pq.push({i[1], i[0], node});
                }
            }
        }
        return {sum, mst};
    }
	
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        // code here
        // vector<vector<vector<int>>> adj(n);
        // for(auto i : edges)
        // {
        //     for(auto j : edges[i])
        //     {
        //         int a = j[0], b = j[1], wt = j[2];
        //         adj[a].push_back({b, wt});
        //         adj[b].push_back({a, wt});
        //     }
        // }
        
        auto mst = minimumSpanningTree(n, adj);
        return mst.first;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends