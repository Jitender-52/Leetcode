class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.rbegin(), maximumHeight.rend());
        int maxi = maximumHeight[0];
        long long ans = maxi;
        for(int i = 1; i < n; i++)
        {
            if(maximumHeight[i] >= maxi)
                maxi = maxi-1;
            else
                maxi = maximumHeight[i];
            if(maxi == 0)
                return -1;
            ans += maxi;
        }
        return ans;
    }
};