class Solution {
public:
    
//     Runtime: 128 ms, faster than 9.61% of C++ online submissions for Minimum Number of Days to Make m Bouquets.
// Memory Usage: 68.9 MB, less than 65.37% of C++ online submissions for Minimum Number of Days to Make m Bouquets.
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int low = 0, high = maxi;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int flowers = 0, bouquet = 0;
            for(int i = 0; i < n; i++)
            {
                if(bloomDay[i] <= mid)
                    flowers++;
                else
                    flowers = 0;
                if(flowers == k)
                {
                    bouquet++;
                    flowers = 0;
                }
            }
            if(bouquet >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if(high + 1 > maxi)
            return -1;
        return high + 1;
    }
};