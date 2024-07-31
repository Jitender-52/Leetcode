class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Filling Bookcase Shelves.
// Memory Usage: 11.2 MB, less than 46.57% of C++ online submissions for Filling Bookcase Shelves.

    vector<int> dp;
    int solve(int idx, vector<vector<int>>& books, int shelfWidth) 
    {
        int n = books.size();
        if (idx == n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        int ans = INT_MAX, maxH = 0, width = 0;
        for (int i = idx; i < n; i++) 
        {
            width += books[i][0];
            if (width > shelfWidth) break;
            maxH = max(maxH, books[i][1]);
            ans = min(ans, maxH + solve(i + 1, books, shelfWidth));
        }
        return dp[idx] = ans;
    }
    
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        dp.resize(n, -1);
        return solve(0, books, shelfWidth);
    }
};