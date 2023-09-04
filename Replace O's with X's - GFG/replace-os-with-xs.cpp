//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector<int> dx = {0, 0, -1, 1};
        vector<int> dy = {1, -1, 0, 0};
        
        auto isValid = [&](int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        auto dfs = [&](int i, int j)
        {
            vis[i][j] = 1;
            queue<pair<int,int>> q;
            q.push({i, j});
            while(!q.empty())
            {
                auto x = q.front().first;
                auto y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(isValid(nx, ny) && !vis[nx][ny] && mat[nx][ny] == 'O')
                    {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        };
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0);
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1);
        }
        for(int j = 0; j < m; j++)
        {
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j);
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1, j);
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j])
                    mat[i][j] = 'X';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends