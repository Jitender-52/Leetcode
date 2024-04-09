class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int ans = (k + 1) * tickets[k] + (n-1-k) * (tickets[k] - 1);
        for(int i = 0; i <= k; i++)
        {
            if(tickets[i] < tickets[k])
                ans -= tickets[k] - tickets[i];
        }
        for(int i = k; i < n; i++)
        {
            if(tickets[i] < tickets[k])
                ans -= tickets[k] - tickets[i] - 1;
        }
        return ans;
    }
};