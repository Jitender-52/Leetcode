class Solution {
public:
    
//     Runtime: 3 ms, faster than 50.89% of C++ online submissions for Maximum Score After Splitting a String.
// Memory Usage: 6.5 MB, less than 87.50% of C++ online submissions for Maximum Score After Splitting a String.
    
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