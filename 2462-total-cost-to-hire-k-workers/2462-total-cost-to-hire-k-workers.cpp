class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>, greater<int>> pq1, pq2;
        int i = 0, j = n-1;
        for(i = 0; i < candidates; i++)
        {
            pq1.push(costs[i]);
            if(j >= candidates)
            {
                pq2.push(costs[j]);
                j--;
            }
        }
        pq1.push(1e9);
        pq2.push(1e9);
        
        long long ans = 0;
        
        while(k--)
        {
            if(pq1.top() <= pq2.top())
            {
                ans += pq1.top();
                pq1.pop();
                if(i <= j)
                {
                    pq1.push(costs[i]);
                    i++;
                }
            }
            else
            {
                ans += pq2.top();
                pq2.pop();
                if(i <= j)
                {
                    pq2.push(costs[j]);
                    j--;
                }
            }
        }
        
        // while(k--)
        // {
        //     if((!pq1.empty() || pq2.empty()) && (pq1.top() <= pq2.top()))
        //     {
        //         ans += pq1.top();
        //         pq1.pop();
        //         if(i <= j)
        //         {
        //             pq1.push(costs[i]);
        //             i++;
        //         }
        //     }
        //     else
        //     {
        //         ans += pq2.top();
        //         pq2.pop();
        //         if(i <= j)
        //         {
        //             pq2.push(costs[j]);
        //             j--;
        //         }
        //     }
        // }
        
        // while(k--)
        // {
        //     if(!pq1.empty() && !pq2.empty())
        //     {
        //         if(pq1.top() <= pq2.top())
        //         {
        //             ans += pq1.top();
        //             pq1.pop();
        //             if(i <= j)
        //             {
        //                 pq1.push(costs[i]);
        //                 i++;
        //             }
        //         }
        //         else
        //         {
        //             ans += pq2.top();
        //             pq2.pop();
        //             if(i <= j)
        //             {
        //                 pq2.push(costs[j]);
        //                 j--;
        //             }
        //         }
        //     }
        //     else if(!pq1.empty())
        //     {
        //         ans += pq1.top();
        //         pq1.pop();
        //     }
        //     else
        //     {
        //         ans += pq2.top();
        //         pq2.pop();
        //     }
        // }
        return ans;
    }
};