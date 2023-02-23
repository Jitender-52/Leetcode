class Solution {
public:
    
//     Runtime: 205 ms, faster than 95.93% of C++ online submissions for IPO.
// Memory Usage: 82.1 MB, less than 53.52% of C++ online submissions for IPO.
    
    
    
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back({capital[i], profits[i]});
        }
        
        sort(v.begin(), v.end());
        
        priority_queue<int, vector<int>> pq;
        
        int j = 0;
        for(int i = 0; i < k; i++)
        {
            while(j < n && v[j].first <= w)
            {
                pq.push(v[j].second);
                j++;
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        
        return w;
            
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> pq;
        
//         for(int i = 0; i < n; i++)
//         {
//             if(profit[i] > capital[i])
//                 pq.push({profit[i] - capital[i], capital[i]});
//         }
        
//         while(k > 0 && !pq.empty())
//         {
//             pair<int,int> p = pq.top();
//             pq.pop();
//             if(p.second <= w)
//             {
//                 w -= p.second;
//                 w += p.first;
//                 k--;
//             }
//         }
//         return w;
    }
};