class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        double x = coordinates[1][0] - coordinates[0][0];
        double y = coordinates[1][1] - coordinates[0][1];
        
        if(y == 0)
        {
            for(int i = 1; i < n; i++)
            {
                if(coordinates[i][1] - coordinates[i-1][1] != 0)
                    return false;
            }
            return true;
        }
        
        for(int i = 1; i < n; i++)
        {
            double a = coordinates[i][0] - coordinates[i-1][0];
            double b = coordinates[i][1] - coordinates[i-1][1];
            if(a / b != x / y)
                return false;
        }
        return true;
    }
};