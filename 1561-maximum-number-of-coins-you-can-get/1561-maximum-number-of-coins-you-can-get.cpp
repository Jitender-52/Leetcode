class Solution {
public:
    
//     Runtime: 133 ms, faster than 7.23% of C++ online submissions for Maximum Number of Coins You Can Get.
// Memory Usage: 54 MB, less than 13.96% of C++ online submissions for Maximum Number of Coins You Can Get.
    
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.rbegin(), piles.rend());
        int ans = 0;
        for(int i = 1; i < n - n/3; i+=2)
            ans += piles[i];
        return ans;
    }
};