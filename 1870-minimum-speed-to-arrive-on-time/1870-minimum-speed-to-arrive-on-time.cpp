class Solution {
public:
    
    double find(vector<int> &dist, int mid)
    {
        int n = dist.size();
        double ans = 0.0;
        for(int i = 0; i < n-1; i++)
        {
            ans += ceil((double)dist[i] / (double)mid);
        }
        ans += ((double)dist[n-1] / (double)mid);
        return ans;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1, r = 1e7;
        if(hour < n-1)
            return -1;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            double ans = find(dist, mid);
            
            if(ans > hour) // becuase speed and time are inversely proportional
                l = mid + 1;
            else
                r = mid - 1;
        }
        return (r + 1) > 1e7 ? -1 : r + 1;
    }
};