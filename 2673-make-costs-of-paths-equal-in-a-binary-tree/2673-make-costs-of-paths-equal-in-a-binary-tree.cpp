class Solution {
public:
    
    int ans = 0;
    
    int dfs(int i, vector<int> &costs)
    {
        if(i >= costs.size())
            return 0;
        int a = dfs(2 * i + 1, costs);
        int b = dfs(2 * i + 2, costs);
        ans += abs(a - b);
        return costs[i] + max(a, b);
    }
    
    int minIncrements(int n, vector<int>& cost) {
        dfs(0, cost);
        return ans;
    }
};