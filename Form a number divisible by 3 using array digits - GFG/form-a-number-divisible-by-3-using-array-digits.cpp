//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int n, int arr[]) {
        // code here
        // map<int,int> mp;
        long long count = 0;
        for(int i = 0; i < n; i++)
        {
            while(arr[i] > 0)
            {
                count += arr[i] % 10;
                arr[i] /= 10;
            }
            // if(mp.find((3 - count % 3) % 3) != mp.end() || count % 3 == 0)
            //     return 1;
            // mp[count % 3]++;
        }
        return count % 3 == 0;
        // if((mp[2] > 0 && mp[1] > 0) || mp[1] >= 3 || mp[2] >= 3)
        //     return 1;
        // return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends