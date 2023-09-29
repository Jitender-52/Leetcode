class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int low = 1, high = 1e5;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            int count = 0;
            for(int i = 0; i < m; i++)
            {
                count += (quantities[i] + (mid - 1))  / mid;
            }
            if(count <= n)
                    high = mid - 1;
            else
                low = mid + 1;
        }
        return high + 1;
    }
};