//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    for(int i = max(1, n - 33); i <= n; i++)
	    {
	        int count = 0;
	        for(int j = 0; j < 31; j++)
	        {
	            if((1 << j) & i)
	                count++;
	        }
	       // cout << i << " " << count << endl;
	        if(count + i == n)
	            return 0;
	    }
	    return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends