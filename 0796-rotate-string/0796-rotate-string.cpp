class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rotate String.
// Memory Usage: 8.8 MB, less than 10.19% of C++ online submissions for Rotate String.
    
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m)
            return false;
        for(int i = 0; i < n; i++)
        {
            if(s.substr(i) + s.substr(0, i) == goal)
                return true;
        }
        return false;
    }
};