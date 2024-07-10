class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Crawler Log Folder.
// Memory Usage: 13.9 MB, less than 61.11% of C++ online submissions for Crawler Log Folder.
    
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto i : logs)
        {
            if(i == "../")
                ans = max(ans - 1, 0);
            else if(i != "./")
                ans++;
        }
        return ans;
    }
};