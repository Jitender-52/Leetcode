class Solution {
public:
    
    
    bool isFeasible(vector<int> &piles, int mid, int h)
    {
        int n = piles.size();
        long long count = 0;
        for(int i = 0; i < n; i++)
        {
                count += ceil(double(piles[i]) / mid);
        }
        return (count <= h);
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        // int mini = n; 
        int mini = 1;
        int maxi = *max_element(piles.begin(), piles.end());
        
        int ans = maxi;
        while(mini <= maxi)
        {
            int mid = (mini + maxi) / 2;
            if(isFeasible(piles, mid, h))
            {
                ans = mid;
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
    
    
    
//     Runtime: 39 ms, faster than 93.73% of C++ online submissions for Koko Eating Bananas.
// Memory Usage: 19.1 MB, less than 11.65% of C++ online submissions for Koko Eating Bananas.

    
//     Main condition to learn about is taking mini and maxi value and to maintain the condition when mid will be zero.
    
    
//     bool isFeasible(vector<int> &piles, int mid, int h)
//     {
//         int n = piles.size();
//         long long count = 0;
//         // cout << mid << endl;
//         for(int i = 0; i < n; i++)
//         {
//             if(mid > 0)
//                 count += ceil(double(piles[i]) / mid);
//         }
//         return (count <= h);
//     }
    
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         // int mini = n; 
//         int mini = 1;
//         int maxi = *max_element(piles.begin(), piles.end());
        
//         int ans = maxi;
//         while(mini <= maxi)
//         {
//             int mid = (mini + maxi) / 2;
//             if(isFeasible(piles, mid, h))
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