class Solution {
public:
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