//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

    const int N = 1001;
    vector<vector<int>> dp;
class Solution{
  public:
  
    vector<vector<int>> dp;
    // int dp[1001][1001];
    string s;
    int minimum(int i, int j)
    {
        if(i == j)
            return 1;
        if(i > j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j] = 2 + minimum(i+1, j-1);
        return dp[i][j] = max(minimum(i+1, j), minimum(i, j-1));
    }
  
    int minimumNumberOfDeletions(string S) { 
        // code here
        s = S;
        int n = s.length();
        dp.resize(n+1, vector<int>(n+1, -1));
        // for(int i = 0; i <= 1000; i++)
        // {
        //     for(int j = 0; j <= 1000; j++)
        //         dp[i][j] = -1;
        // }
        return n - minimum(0, n-1);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends