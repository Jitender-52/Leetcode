class Solution {
public:
    
//     Runtime: 216 ms, faster than 11.26% of C++ online submissions for Minimum Number of Days to Disconnect Island.
// Memory Usage: 20.4 MB, less than 65.93% of C++ online submissions for Minimum Number of Days to Disconnect Island.

    const vector<vector<int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int countIslands(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        for (int row = 0; row < rows; row++) 
        {
            for (int col = 0; col < cols; col++) 
            {
                if (!visited[row][col] && grid[row][col] == 1) 
                {
                    exploreIsland(grid, row, col, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }

    void exploreIsland(vector<vector<int>>& grid, int row, int col,
                       vector<vector<bool>>& visited) 
    {
        visited[row][col] = true;
        for (const auto& direction : DIRECTIONS) 
        {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            // Explore if valid land cell
            if (isValidLandCell(grid, newRow, newCol, visited)) 
                exploreIsland(grid, newRow, newCol, visited);
        }
    }

    bool isValidLandCell(const vector<vector<int>>& grid, int row, int col, const vector<vector<bool>>& visited) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        return row >= 0 && col >= 0 && row < rows && col < cols && grid[row][col] == 1 && !visited[row][col];
    }
    
    int minDays(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int initialIslandCount = countIslands(grid);

        if (initialIslandCount != 1) 
            return 0;

        for (int row = 0; row < rows; row++) 
        {
            for (int col = 0; col < cols; col++) 
            {
                if (grid[row][col] == 0) 
                    continue;
                grid[row][col] = 0;
                int newIslandCount = countIslands(grid);

                if (newIslandCount != 1) 
                    return 1;

                grid[row][col] = 1;
            }
        }
        return 2;
    }
};