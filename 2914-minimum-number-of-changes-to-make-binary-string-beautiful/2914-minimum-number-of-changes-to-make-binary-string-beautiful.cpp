class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Changes to Make Binary String Beautiful.
// Memory Usage: 12.2 MB, less than 16.88% of C++ online submissions for Minimum Number of Changes to Make Binary String Beautiful.
    
    int minChanges(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++)
        {
            char a = s[i];
            int count = 0;
            while(i < n && s[i] == a)
            {
                count++;
                i++;
            }
            if(count % 2 == 1)
                ans++;
            else
                i--;
        }
        return ans;
    }
};