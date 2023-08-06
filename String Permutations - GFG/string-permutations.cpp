//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void permutations(string &p, string &s, vector<string> &ans, vector<int> &vis)
    {
        int n = s.length();
        if(p.length() == n)
        {
            ans.push_back(p);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                vis[i] = 1;
                p += s[i];
                permutations(p, s, ans, vis);
                p.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    vector<string> permutation(string s)
    {
        //Your code here
        int n = s.length();
        vector<int> vis(n, 0);
        vector<string> ans;
        string p = "";
        permutations(p, s, ans, vis);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends