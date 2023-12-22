class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int zero = 0, one = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                one++;
        }
        int ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(s[i] == '0')
                zero++;
            else
                one--;
            ans = max(ans, zero + one);            
        }
        return ans;
    }
};