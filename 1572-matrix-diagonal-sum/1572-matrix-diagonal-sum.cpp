class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < n && j < n)
        {
            ans += mat[i][j];
            i++;
            j++;
        }
        i = n-1;
        j = 0;
        while(i >= 0 && j < n)
        {
            if(i != j)
                ans += mat[i][j];
            i--;
            j++;
        }
        return ans;
    }
};