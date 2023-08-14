class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> count(2e4+2, 0);
        int &mini = *min_element(nums.begin(), nums.end());
        for(auto i : nums)
            count[i - mini]++;
  
        for(int i = count.size()-1; i >= 0; i--)
        {
            k -= count[i];
            if(k <= 0)
                return i + mini;
        }
        return mini;
    }
};
    
    
//     Runtime: 101 ms, faster than 73.98% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 47.4 MB, less than 33.60% of C++ online submissions for Kth Largest Element in an Array.

    
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         priority_queue<int,vector<int>, greater<int>> pq;
//         for(auto i : nums)
//         {
//             pq.push(i);
//             if(pq.size() > k)
//                 pq.pop();
//         }
//         return pq.top();
//     }
// };