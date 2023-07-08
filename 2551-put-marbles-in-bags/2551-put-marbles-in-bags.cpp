class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(k == n || k == 1)
            return 0;
        
        vector<long long> v;
        for(int i = 0; i < n-1; i++)
        {
            v.push_back(weights[i] + weights[i+1]);
        }
        
        sort(v.begin(), v.end());
        
        long long sum1 = 0;
        long long sum2 = 0;
        int m = v.size();
        for(int i = 0; i < k-1 && i < m; i++)
        {
            sum1 += v[i];
        }
        int x = 0;
        for(int i = m-1; i >= 0 && x < k -1; i--)
        {
            sum2 += v[i];
            x++;
        }
        
        return sum2 - sum1;
        
        
//         int mini = INT_MAX;
        
//         // int m = v.size();
// //         sort(v.begin(), v.end());
// //         for(int i = 0; i < m; i++)
// //         {
               
// //         }
        
        
//         priority_queue<int, vector<int>, greater<int>> pq;
        
//         for(int i = 0; i < m; i++)
//         {
//             pq.push(v[i]);
//         }
        
//         int sum1 = 0;
//         for(int i = 0; i < k-1; i++)
//         {
//             sum1 += pq.top();
//             pq.pop();
//         }
        
// //         if(pq.top() == v[0] && pq.top() == v[m-1])
// //         {
// //             sum1 += 2 * min(weights[0], weights[n-1]);
// //             pq.pop();
            
// //             if(pq.top() == v[0])
// //             {
// //                 sum += 
// //             }
// //         }
        
//         if(v[0] > v[m-1])
//         {
//             if(pq.top() > v[0])
//             {
//                 sum1 += 2 * weights[0];
//             }
//             else
//             {
//                 sum1 += weights[0];
//             }
//             if(v[0] == pq.top())
//                 pq.pop();
//         }
    }
};