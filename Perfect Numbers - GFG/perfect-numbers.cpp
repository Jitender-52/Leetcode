//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        // code here
        long long sum = 0;
        if(n != 1)
            sum += 1;
        for(long long i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                long long a = n / i;
                if(a != n && a != i)
                    sum += a;
                sum += i;
            }
        }
        return sum == n;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends