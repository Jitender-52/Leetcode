class Solution {
public:
    
//     Runtime: 107 ms, faster than 95.68% of C++ online submissions for Magnetic Force Between Two Balls.
// Memory Usage: 61.5 MB, less than 35.79% of C++ online submissions for Magnetic Force Between Two Balls.
    
//     Runtime: 137 ms, faster than 16.37% of C++ online submissions for Magnetic Force Between Two Balls.
// Memory Usage: 61.4 MB, less than 35.79% of C++ online submissions for Magnetic Force Between Two Balls.
    
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 0, high = (position[n-1] - position[0]) / (m - 1);
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int last = -1e9;
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(position[i] - last >= mid)
                {
                    count++;
                    last = position[i];
                }
                if(count >= m)
                    break;
            }
            if(count >= m)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low - 1;
    }
};