class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0, down = n-1;
        int left = 0, right = m-1;
        int x = 0;
        vector<int> ans;
        while(left <= right && top <= down)
        {
            if(x == 0)
            {
                for(int i = left; i <= right; i++)
                    ans.push_back(matrix[top][i]);
                top = top + 1;
            }
            else if(x == 1)
            {
                for(int i = top; i <= down; i++)
                    ans.push_back(matrix[i][right]);
                right = right - 1;
            }
            else if(x == 2)
            {
                for(int i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down = down - 1;
            }
            else if(x == 3)
            {
                for(int i = down; i >= top;i--)
                    ans.push_back(matrix[i][left]);
                left = left + 1;
            }
            x = (x + 1) % 4;
        }
        return ans;
    }
};