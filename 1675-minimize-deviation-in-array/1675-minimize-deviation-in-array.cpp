class Solution {
public:
    
//     Runtime: 591 ms, faster than 46.61% of C++ online submissions for Minimize Deviation in Array.
// Memory Usage: 56.7 MB, less than 88.98% of C++ online submissions for Minimize Deviation in Array.

    
    
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        
        // priority_queue<int, vector<int>> pq;
        priority_queue<int> pq;
        
        int mini = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2)
                nums[i] *= 2;
            pq.push(nums[i]);
            mini = min(mini, nums[i]);
        }
        
        int ans = INT_MAX;
        while(1)
        {
            int top = pq.top();
            pq.pop();
            ans = min(ans, abs(top - mini));
            if(top % 2 == 1)
                break;
            top /= 2;
            mini = min(mini, top);
            pq.push(top);
        }
        return ans;
    }
};