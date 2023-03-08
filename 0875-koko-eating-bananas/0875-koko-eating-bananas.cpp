class Solution {
public:
    
    bool isFeasible(vector<int> &piles, int mid, int h)
    {
        int n = piles.size();
        long long count = 0;
        // cout << mid << endl;
        for(int i = 0; i < n; i++)
        {
            if(mid > 0)
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