//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       int n = s.length();
       map<char,int> mp;
       for(int i = 0; i < n; i++)
       {
            if(mp[s[i]] == 0)
                mp[s[i]] = i + 1;
            else
                mp[s[i]] = n + 5;
       }
       
       char ans = '$';
       int a = n+1;
       for(auto i : mp)
       {
           if(i.second < a)
           {
               a = i.second;
               ans = i.first;
           }
       }
       return ans;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends