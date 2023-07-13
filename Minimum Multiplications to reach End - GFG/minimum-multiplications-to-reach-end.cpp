//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    const int mod = 1e5;
  
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        vector<int> dist(1e5, 1e9);
        queue<pair<int, int>> q;
        q.push({start, 0});
        dist[start] = 0;
        int steps = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int j = 0; j < sz; j++)
            {
                auto node = q.front().first;
                auto d = q.front().second;
                q.pop();
                if(node == end)
                    return steps;
                for(int i = 0; i < n; i++)
                {
                    int nnode = (arr[i] * node) % mod;
                    if(nnode == end)
                        return steps + 1;
                    if(steps + 1 < dist[nnode])
                    {
                        dist[nnode] = steps + 1;
                        if(nnode != 0)
                            q.push({nnode, steps + 1});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends