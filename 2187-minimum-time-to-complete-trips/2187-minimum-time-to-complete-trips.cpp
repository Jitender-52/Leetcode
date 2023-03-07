class Solution {
public:
    
    bool isFeasible(vector<int> &time, long long t, long long maxi)
    {
        int n = time.size();
        long long count = 0;
        for(int i = 0; i < n; i++)
        {
            count += maxi / time[i];
        }
        return count >= t;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());
        
        long long maxi = time[0] *1LL * totalTrips;
        // long long maxi = 1e10;
        // long long mini = totalTrips / time[n-1];
        long long mini = totalTrips / (time[0] * n);
        // long long mini = 0;
        long long ans = maxi;
        
        while(mini <= maxi)
        {
            long long mid = (mini + maxi) / 2;
            if(isFeasible(time, totalTrips, mid))
            {
                ans = min(ans, mid);
                maxi = mid - 1;
            }    
            else
            {
                mini = mid + 1;
            }
        }
        return ans;
    }
};