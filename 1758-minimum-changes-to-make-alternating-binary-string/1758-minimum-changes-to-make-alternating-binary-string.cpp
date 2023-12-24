class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string t = s;
        int ans = n, count = 0;
        for(int i = 0; i < n; i+=2)
        {
            if(s[i] == '0')
                count++;
            if(i + 1 < n && s[i+1] == '1')
                count++;
        }
        ans = min(ans, count);
        count = 0;
        for(int i = 0; i < n; i+=2)
        {
            if(s[i] == '1')
                count++;
            if(i + 1 < n && s[i+1] == '0')
                count++;
        }
        ans = min(ans, count);
        return ans;
    }
};