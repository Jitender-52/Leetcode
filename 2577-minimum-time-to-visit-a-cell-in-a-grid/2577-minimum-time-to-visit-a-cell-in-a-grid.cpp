class Solution {
public:
    
//     Runtime: 816 ms, faster than 18.02% of C++ online submissions for Minimum Time to Visit a Cell In a Grid.
// Memory Usage: 173.1 MB, less than 16.71% of C++ online submissions for Minimum Time to Visit a Cell In a Grid.
    
    bool isValid(vector<vector<bool>>& visited, int row, int col)
    {
        return row >= 0 && col >= 0 && row < visited.size() && col < visited[0].size() && !visited[row][col];
    }
    
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) 
            return -1;
        
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            if (row == rows - 1 && col == cols - 1) 
                return time;

            if (visited[row][col]) 
                continue;
            visited[row][col] = true;

            for (auto& d : directions) 
            {
                int nextRow = row + d[0], nextCol = col + d[1];
                if (!isValid(visited, nextRow, nextCol)) 
                    continue;
                
                int waitTime = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                int nextTime = max(grid[nextRow][nextCol] + waitTime, time + 1);
                pq.push({nextTime, nextRow, nextCol});
            }
        }
        return -1;
    }
};