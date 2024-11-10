class Solution {
public:
    
    
 // Already Solved in the question https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/?envType=daily-question&envId=2024-11-07  
    
    // Similar solution done in the above question by mistake only difference is of OR and AND ans smallest and lareges
    
    
//     Runtime: 874 ms, faster than 7.69% of C++ online submissions for Shortest Subarray With OR at Least K II.
// Memory Usage: 88.7 MB, less than 28.97% of C++ online submissions for Shortest Subarray With OR at Least K II.

    
    bool hasValidSubarray(vector<int>& nums, int targetSum, int windowSize) 
    {
        int arrayLength = nums.size();
        vector<int> bitCounts(32, 0); 

        for (int right = 0; right < arrayLength; right++) 
        {
            updateBitCounts(bitCounts, nums[right], 1);
            if (right >= windowSize) 
                updateBitCounts(bitCounts, nums[right - windowSize], -1);

            if (right >= windowSize - 1 &&
                convertBitCountsToNumber(bitCounts) >= targetSum) 
                return true;
        }
        return false;
    }

    void updateBitCounts(vector<int>& bitCounts, int number, int delta) 
    {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++)
        {
            if (((number >> bitPosition) & 1) != 0) 
                bitCounts[bitPosition] += delta;
        }
    }

    int convertBitCountsToNumber(vector<int>& bitCounts)
    {
        int number = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) 
        {
            if (bitCounts[bitPosition] != 0) 
                number |= 1 << bitPosition;
        }
        return number;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 1;
        int right = nums.size();
        int minLength = -1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (hasValidSubarray(nums, k, mid)) 
            {
                minLength = mid;
                right = mid - 1;
            }
            else 
                left = mid + 1;  
        }

        return minLength;
    }
};