class KthLargest {
public:
    
    priority_queue<int,vector<int>, greater<int>> pq;
    int a;
    
    KthLargest(int k, vector<int>& nums) {
        a = k;
        for(auto &i : nums)
            pq.push(i);
        while(pq.size() > k)
            pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > a)
            pq.pop();
        return pq.top();
    }
};
    
    
//     Runtime: 1493 ms, faster than 5.04% of C++ online submissions for Kth Largest Element in a Stream.
// Memory Usage: 21.6 MB, less than 5.28% of C++ online submissions for Kth Largest Element in a Stream.
    
    // map<int,int> mp;
    // int a;
    
//     KthLargest(int k, vector<int>& nums) {
//         for(auto &i : nums)
//             mp[i]++;
//         a = k;
//     }
    
//     int add(int val) {
//         int count = 0;
//         mp[val]++;
//         // for(auto it = mp.rbegin(); it != mp.rend(); it++)
//         // {
//         //     for(int j = 0; j < it->second; j++)
//         //         cout << it->first << " ";
//         // }
//         // cout << endl;
        
//         for(auto it = mp.rbegin(); it != mp.rend(); it++)
//         {
//             count += it->second;
//             if(count >= a)
//                 return it->first;
//         }
//         return 0;
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */