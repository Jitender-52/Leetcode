class Solution {
public:
    
//     Runtime: 226 ms, faster than 59.36% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.
// Memory Usage: 47.9 MB, less than 66.67% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.
    
    int backtrack(const string& s, int start, unordered_set<string>& seen) 
    {
        if (start == s.size())
            return 0;
        int maxCount = 0;
        for (int end = start + 1; end <= s.size(); end++) 
        {
            string substring = s.substr(start, end - start);
            if (seen.find(substring) == seen.end()) 
            {
                seen.insert(substring);
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                seen.erase(substring);
            }
        }
        return maxCount;
    }
    
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }
};