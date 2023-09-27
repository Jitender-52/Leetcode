//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        set<int> st;
        for(int i = 0; i < m; i++)
            st.insert(brr[i]);
        int ans = 1e9;
        st.insert(-1e9);
        st.insert(2e9);
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int a = x - arr[i];
            auto it = st.lower_bound(a);
            if(*it - a < ans)
                v = {*it, arr[i]};
            ans = min(ans, *it - a);
            it--;
            if(a - *it < ans)
                v = {*it, arr[i]};
            ans = min(ans, a - *it);
        }
        // cout << v[0] << " " << v[1] << endl;
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends