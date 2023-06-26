class Solution {
public:
    
//     Runtime: 196 ms, faster than 82.48% of C++ online submissions for Total Cost to Hire K Workers.
// Memory Usage: 72.8 MB, less than 82.21% of C++ online submissions for Total Cost to Hire K Workers.
    
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<int,vector<int>, greater<int>> pq1, pq2;
        int i = 0, j = n-1;
        for(i = 0; i < candidates; i++)
        {
            pq1.push(costs[i]);
            
            // Doing mistake so made three different methods 
            if(j >= candidates)
            {
                pq2.push(costs[j]);
                j--;
            }
        }
        pq1.push(1e9);
        pq2.push(1e9);
        
        long long ans = 0;
        
        // 1st method
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
        
        // 2nd method
//         while(k--)
//         {
//             if((!pq1.empty() || pq2.empty()) && (pq1.top() <= pq2.top()))
//             {
//                 ans += pq1.top();
//                 pq1.pop();
//                 if(i <= j)
//                 {
//                     pq1.push(costs[i]);
//                     i++;
//                 }
//             }
//             else
//             {
//                 ans += pq2.top();
//                 pq2.pop();
//                 if(i <= j)
//                 {
//                     pq2.push(costs[j]);
//                     j--;
//                 }
//             }
//         }
        
        // 3rd method
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