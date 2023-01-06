class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int ans = 0;
        int i = 0;
        while(i < n)
        {
            if(costs[i] > coins)
                break;
            ans++;
            coins -= costs[i];
            i++;
        }
        return ans;
    }
};