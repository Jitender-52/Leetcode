class Solution {
public:
    
    vector<int> lps;
    void solve(string a)
    {
        int i = 0, j = 1;
        while(j < a.length())
        {
            if(a[i] == a[j])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if(i == 0)
                    j++;
                else
                    i = lps[i-1];
            }
        }
    }
    
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string a = s + '#' + t;
        int n = a.length();   
        lps.resize(n, 0);
        solve(a);
        int i = lps[n-1];
        string temp = s.substr(i);
        reverse(temp.begin(), temp.end());
        return temp + s;
    }
};