class Solution {
public:
    
    bool isFeasible(vector<int> &weights, int maxi, int days)
    {
        int n = weights.size();
        int count = 0;
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(weights[i] > maxi)
                return false;
            if(sum + weights[i] > maxi)
            {
                sum = 0;
                count++;
            }
            sum += weights[i];
        }
        count++;
        // cout << "count = " << count << endl;
        if(count <= days)
            return true;
        return false;
    }
    
    int minimum(vector<int> &weights, int days)
    {
        int n = weights.size();
        int ans = INT_MAX;
        int left = INT_MAX;
        int right = 0;
        for(int i = 0; i < n; i++)
        {
            left = min(left, weights[i]);
            right += weights[i];
        }
    
        while(left <= right)
        {
            int mid = (left + right) / 2;
            // cout << mid << endl;
            if(isFeasible(weights, mid, days))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
           
        }
        // cout << endl;
        return ans;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        return minimum(weights, days);
    }
};