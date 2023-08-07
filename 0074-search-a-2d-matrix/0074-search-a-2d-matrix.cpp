class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(matrix[mid][0] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        int row = l-1;
        if(row < 0)
            return 0;
        l = 0, r = m-1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(matrix[row][mid] > target)
            {
                r = mid-1;
            }
            else
                l = mid + 1;
        }
        
        int col = l - 1;
        if(col < 0)
            return 0;
        return matrix[row][col] == target;
    }
};