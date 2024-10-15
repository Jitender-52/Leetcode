class Solution {
public:
    
//     Runtime: 24 ms, faster than 93.05% of C++ online submissions for Separate Black and White Balls.
// Memory Usage: 19.1 MB, less than 9.68% of C++ online submissions for Separate Black and White Balls.
    
    long long minimum(string s)
    {
        int n = s.length();
        long long sum = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                sum += (0LL + i+1);
                count++;
            }
        }
        return sum - (count * (count + 1))/2;
    }
    
    long long minimumSteps(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return minimum(t);
    }
};