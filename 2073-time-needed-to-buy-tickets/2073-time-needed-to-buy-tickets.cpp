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
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Time Needed to Buy Tickets.
// Memory Usage: 9.3 MB, less than 91.31% of C++ online submissions for Time Needed to Buy Tickets.
    
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         int n = tickets.size();
//         int ans = (k + 1) * tickets[k] + (n-1-k) * (tickets[k] - 1);
//         for(int i = 0; i <= k; i++)
//         {
//             if(tickets[i] < tickets[k])
//                 ans -= tickets[k] - tickets[i];
//         }
//         for(int i = k; i < n; i++)
//         {
//             if(tickets[i] < tickets[k])
//                 ans -= tickets[k] - tickets[i] - 1;
//         }
//         return ans;
//     }
// };