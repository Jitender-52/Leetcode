class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Take K of Each Character From Left and Right.
// Memory Usage: 12.2 MB, less than 56.21% of C++ online submissions for Take K of Each Character From Left and Right.
    
    int takeCharacters(string s, int k) {
        int n = s.length();
        int a = 0;
        int b = 0;
        int c = 0;
        
        if(k == 0)
            return 0;
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'a')
            {
                a++;
            }
            if(s[i] == 'b')
            {
                b++;
            }
            if(s[i] == 'c')
            {
                c++;
            }
        }
        
        if(a < k || b < k || c < k)
            return -1;
        
        int i = 0;
        int j = 0;
        
        int d1 = a - k;
        int d2 = b - k;
        int d3 = c - k;
        
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        
        
        int ans = 0;
        // ans = max(ans, j - i + 1);
        
        while(j < n && i < n)
        {
            if(c1 <= d1 && c2 <= d2 && c3 <= d3)
            {
                // cout << i << " " << j << endl;
                ans = max(ans, j-i);
                
                
                if(s[j] == 'a')
                {
                    c1++;
                }
                if(s[j] == 'b')
                {
                    c2++;
                }
                if(s[j] == 'c')
                {
                    c3++;
                }
                j++;
                
            }
            else
            {
                if(s[i] == 'a')
                {
                    c1--;
                }
                if(s[i] == 'b')
                {
                    c2--;
                }
                if(s[i] == 'c')
                {
                    c3--;
                }
                i++;
                           }
        }
        
        if(c1 <= d1 && c2 <= d2 && c3 <= d3)
            {
                // cout << i << " " << j << endl;
                ans = max(ans, j-i);
            }
        
        // cout << ans << endl;
        return n - ans;
    }
};