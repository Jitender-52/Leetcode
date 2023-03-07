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
        
        long long mini = 1;
        long long maxi = *max_element(time.begin(), time.end()) * 1LL * totalTrips;
        
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
    
    
    
//     Runtime: 283 ms, faster than 84.43% of C++ online submissions for Minimum Time to Complete Trips.
// Memory Usage: 94.5 MB, less than 33.40% of C++ online submissions for Minimum Time to Complete Trips.
    
//     Runtime: 383 ms, faster than 63.23% of C++ online submissions for Minimum Time to Complete Trips.
// Memory Usage: 94.4 MB, less than 76.55% of C++ online submissions for Minimum Time to Complete Trips.
    
    
//     bool isFeasible(vector<int> &time, long long t, long long maxi)
//     {
//         int n = time.size();
//         long long count = 0;
//         for(int i = 0; i < n; i++)
//         {
//             count += maxi / time[i];
//         }
//         return count >= t;
//     }
    
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         int n = time.size();
//         // sort(time.begin(), time.end());
        
//         // long long maxi = time[0] *1LL * totalTrips;
//         // // long long maxi = 1e10;
//         // // long long mini = totalTrips / time[n-1];
//         // long long mini = totalTrips / (time[0] * n);
//         // // long long mini = 0;
        
//         long long maxi = *min_element(time.begin(), time.end()) * 1LL * totalTrips;
//         long long mini = totalTrips / (*min_element(time.begin(), time.end()) * n);
        
//         long long ans = maxi;
        
//         while(mini <= maxi)
//         {
//             long long mid = (mini + maxi) / 2;
//             if(isFeasible(time, totalTrips, mid))
//             {
//                 ans = min(ans, mid);
//                 maxi = mid - 1;
//             }    
//             else
//             {
//                 mini = mid + 1;
//             }
//         }
//         return ans;
//     }
// };