//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here
	    vector<int> vis(v, 0);
	    queue<int> q;
	    q.push(0);
	    vis[0] = 1;
	    int ans = 0;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i = 0; i < sz; i++)
	        {
	            auto node = q.front();
	            if(node == x)
	                return ans;
	            q.pop();
	            for(auto neighbour : adj[node])
	            {
	                if(!vis[neighbour])
	                {
	                    vis[neighbour] = 1;
	                    q.push(neighbour);
	                }
	            }
	        }
	        ans++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends