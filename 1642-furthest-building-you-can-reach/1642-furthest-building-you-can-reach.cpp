class Solution {
public:
    
//     Runtime: 84 ms, faster than 38.71% of C++ online submissions for Furthest Building You Can Reach.
// Memory Usage: 57.2 MB, less than 40.68% of C++ online submissions for Furthest Building You Can Reach.
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            
            if (diff > 0) {
                pq.push(diff);
                
                if (pq.size() > ladders) {
                    int highest_diff = pq.top();
                    pq.pop();
                    bricks -= highest_diff;
                    
                    if (bricks < 0) {
                        return i;
                    }
                }
            }
        }
        
        return heights.size() - 1;
    }
};