class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Swap.
// Memory Usage: 7.8 MB, less than 12.29% of C++ online submissions for Maximum Swap.
    
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        int ans = num; 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                swap(s[i], s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return ans;
    }
};