class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int ans = 0;
        for(int i = 0; i <= min(n, 1000); i++)
        {
            auto it = citations.end() - lower_bound(citations.begin(), citations.end(), i);
            if(it >= i)
                ans = max(ans, i);
        }
        return ans;
    }
};