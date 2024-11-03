class Solution {
public:
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