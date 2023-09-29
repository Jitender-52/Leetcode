//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        if(m > n)
            return -1;
        int low = 0, high = 1e6;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int count = 1, sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += a[i];
                if(sum > mid)
                {
                    sum = a[i];
                    count++;
                }
                if(a[i] > mid)
                    count = m+1;
            }
            // cout << mid << " " << count << endl;
            if(count <= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high + 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends