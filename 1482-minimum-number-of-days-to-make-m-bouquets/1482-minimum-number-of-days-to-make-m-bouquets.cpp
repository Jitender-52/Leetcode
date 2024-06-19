class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = 0, high = 1e9 + 2;
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
        if(high + 1 > 1e9)
            return -1;
        return high + 1;
    }
};