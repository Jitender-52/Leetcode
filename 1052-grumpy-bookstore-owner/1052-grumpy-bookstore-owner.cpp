class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++)
            sum += (1 - grumpy[i]) * customers[i];
        int j = 0;
        for(int i = 0; i < minutes; i++)
            sum += grumpy[i] * customers[i];
        ans = max(ans, sum);
        for(int i = minutes; i < n; i++, j++)
        {
            sum -= (1 & grumpy[j]) * customers[j] - (grumpy[i]) * customers[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};