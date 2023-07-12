//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    
    // Using Set
    
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        // Code here
        
        set<pair<int, int>> st;
        vector<int> dist(n, 1e9);
    
        st.insert({0, s});
        dist[s] = 0;
    
        while (!st.empty())
        {
            auto it = st.begin();
            int d = it->first; // because it is a pointer if we want to access it using dot then use *before st.begin();
            int node = it->second;
            st.erase(it);
            for (auto i : adj[node])
            {
                int wt = i[1];
                int nnode = i[0];
                if (wt + d < dist[nnode])
                {
                    if (dist[nnode] != 1e9)
                        st.erase({dist[nnode], nnode});
                    dist[nnode] = wt + d;
                    st.insert({wt + d, nnode});
                }
            }
        }
        return dist;
    }
};

    
    
    
    // Using priority_queue
    
//     vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
//     {
//         // Code here
        
//         vector<int> dist(n, 1e9);
//         dist[s] = 0;
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         pq.push({0, s});
        
//         while(!pq.empty())
//         {
//             int d = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
//             for(auto it : adj[node])
//             {
//                 int wt = it[1];
//                 int nnode = it[0];
                
//                 if(d + wt < dist[nnode])
//                 {
//                     dist[nnode] = d + wt;
//                     pq.push({dist[nnode], nnode});
//                 }
//             }
//         }
//         return dist;
//     }
// };


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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends