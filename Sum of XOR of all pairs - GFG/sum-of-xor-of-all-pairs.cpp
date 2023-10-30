//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	int long long ans = 0;
    	
    	for(int i = 0; i < 32; i++)
    	{
    	    int count = 0;
    	    for(int j = 0; j < n; j++)
    	    {
    	        if((1 << i) & arr[j])
    	            count++;
    	    }
    	    if(count == 0)
    	        continue;
    	    for(int j = 0; j < n; j++)
    	    {
    	        if((1 << i) & arr[j])
    	        {
    	            ans += (1 << i) * 1LL * (n - count);
    	        }
    	        else
    	        {
    	            ans += (1 << i) * 1LL * (count);
    	        }
    	    }
    	}
    	return ans / 2;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends