class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
            v.push_back({difficulty[i], profit[i]});
        sort(v.begin(), v.end());
        sort(worker.begin(), worker.end());
        int ans = 0, maxi = 0, j = 0;
        for(auto i : worker)
        {
            while(j < m && i >= v[j].first)
            {
                maxi = max(maxi, v[j].second);
                j++;
            }
            ans += maxi;
        }
        return ans;
    }
};