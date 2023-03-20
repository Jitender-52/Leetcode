class Solution {
public:
    
//     Runtime: 11 ms, faster than 97.02% of C++ online submissions for Can Place Flowers.
// Memory Usage: 20.3 MB, less than 34.30% of C++ online submissions for Can Place Flowers.
    
    
    bool canPlaceFlowers(vector<int>& flowerbed, int x) {
        int n = flowerbed.size();
        
        if(x == 0)
            return true;
        
        for(int i = 0; i < n; i++)
        {
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == n-1 || flowerbed[i+1] == 0))
            {
                flowerbed[i] = 1;
                x--;
            }
            if(x <= 0)
                return true;
        }
        return false;
    }
};