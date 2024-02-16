class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp;
        for(auto i : arr)
            mp[i]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i : mp)
            pq.push(i.second);
        while(!pq.empty() && k--)
        {
            int a = pq.top()-1;
            pq.pop();
            if(a != 0)
                pq.push(a);
        }
        return pq.size();        
    }
};
    
//     Runtime: 285 ms, faster than 9.50% of C++ online submissions for Least Number of Unique Integers after K Removals.
// Memory Usage: 91.2 MB, less than 5.91% of C++ online submissions for Least Number of Unique Integers after K Removals.
    
//     int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//         map<int,int> mp;
//         for(auto i : arr)
//             mp[i]++;
//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//         for(auto i : mp)
//         {
//             pq.push({i.second, i.first});
//         }
//         while(!pq.empty() && k--)
//         {
//             int a = pq.top()[0];
//             int b = pq.top()[1];
//             pq.pop();
//             a--;
//             if(a != 0)
//                 pq.push({a, b});
//         }
//         return pq.size();        
//     }
// };