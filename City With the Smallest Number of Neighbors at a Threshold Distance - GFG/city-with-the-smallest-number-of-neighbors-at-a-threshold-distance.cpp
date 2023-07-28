//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    }
  
    // static bool comp(vector<int> &a, vector<int> &b)
    // {
    //     if(a[0] == b[0])
    //         return a[1] > b[1];
    //     return a[0] < b[0];
    // }
  
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));
        for(auto i : edges)
        {
            matrix[i[0]][i[1]] = i[2];
            matrix[i[1]][i[0]] = i[2];
        }
        
        for(int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }
        
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j])
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
        
        vector<pair<int,int>> v;
        // vector<vector<int>> v;
        for(int i = 0; i < n; i++)
        {
            int count = 0;
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] <= distanceThreshold)
                {
                    count++;
                }
            }
            v.push_back({count, i});
        }
        sort(v.begin(), v.end(), comp);
        // return v[0][1];
        return v[0].second;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends