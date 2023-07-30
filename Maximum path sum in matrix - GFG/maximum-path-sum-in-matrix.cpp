//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        int ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                int a = 0;
                a = max(a, matrix[i-1][j]);
                if(i > 0)
                    a = max(a, matrix[i-1][j-1]);
                if(j < n-1)
                    a = max(a, matrix[i-1][j+1]);
                matrix[i][j] += a;
            }
        }
        for(int j = 0; j < n; j++)
        {
            ans = max(ans, matrix[n-1][j]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends