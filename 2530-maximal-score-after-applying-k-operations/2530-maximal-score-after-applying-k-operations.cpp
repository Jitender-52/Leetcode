class Solution {
public:
    
//     Runtime: 209 ms, faster than 18.95% of C++ online submissions for Maximal Score After Applying K Operations.
// Memory Usage: 79.8 MB, less than 50.62% of C++ online submissions for Maximal Score After Applying K Operations.
    
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        
        priority_queue<int, vector<int>> pq;
        
        for(int i = 0; i < n; i++)
            pq.push(nums[i]);
        
        for(int i = 0; i < k; i++)
        {
            ans += pq.top();
            double a = pq.top();
            pq.pop();
            int b = ceil(a/3.0);
            pq.push(b);
        }
        return ans;
    }
};