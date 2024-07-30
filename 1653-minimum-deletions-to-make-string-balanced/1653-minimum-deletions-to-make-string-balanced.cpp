class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> a(n), b(n);
        a[n-1] = s[n-1] == 'a';
        b[0] = s[0] == 'b';
        for(int i = 1; i < n; i++)
            b[i] = b[i-1] + (s[i] == 'b');
        for(int i = n-2; i >= 0; i--)
            a[i] = a[i+1] + (s[i] == 'a');
        int ans = min(a[0], b[n-1]);
        for(int i = 1; i < n-1; i++)
            ans = min(ans, a[i+1] + b[i-1]);
        return ans;
    }
};