class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double ans = 0;
        int a = 0;
        for(int i = 0; i < n; i++)
        {
            a = max(customers[i][0] + customers[i][1], a + customers[i][1]);
            ans += (double)(a - customers[i][0]) / n;
        }
        return ans;
    }
};