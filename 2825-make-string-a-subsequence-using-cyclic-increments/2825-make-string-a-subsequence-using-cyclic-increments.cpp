class Solution {
public:
    
//     Runtime: 3 ms, faster than 66.85% of C++ online submissions for Make String a Subsequence Using Cyclic Increments.
// Memory Usage: 17.1 MB, less than 7.53% of C++ online submissions for Make String a Subsequence Using Cyclic Increments.
    
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        
        int j = 0;
        char a = '*', c = '&', d = '(';
        int i = 0;
        for(i = 0; i < m; i++)
        {
            a = str2[i];
            bool check = false;
            while(j < n)
            {
                char c = str1[j];
                char d = c;
                d++;
                if(c == 'z')
                    d = a;
                j++;
                if(a == c || a == d)
                {
                    check = true;
                    break;
                }
            }
            if(!check)
                break;
        }
        return i == m;
    }
};