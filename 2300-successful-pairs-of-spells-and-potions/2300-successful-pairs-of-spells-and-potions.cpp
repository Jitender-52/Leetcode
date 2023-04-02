class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int m = spells.size();
        int n = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans(m);
        for(int i = 0; i < m; i++)
        {
            long long x = ceil(double(success)/spells[i]);
            int low = 0;
            int high = n-1;
            int mini = n;
            // cout << "x = " << x << endl;
            while(low <= high)
             {
                int mid = (low + high) / 2;
                if(potions[mid] < x)
                {
                    low = mid+1;
                }
                else
                {
                    mini = min(mini, mid);
                    high = mid-1;
                }
             }
            // cout << mini << endl;
             ans[i] = n - mini;
        }
        return ans;
    }
};