class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int x) {
        int n = flowerbed.size();
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