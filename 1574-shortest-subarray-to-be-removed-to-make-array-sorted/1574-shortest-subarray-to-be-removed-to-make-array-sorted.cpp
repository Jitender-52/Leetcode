class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.
// Memory Usage: 69.4 MB, less than 98.14% of C++ online submissions for Shortest Subarray to be Removed to Make Array Sorted.
    
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        while (right > 0 && arr[right] >= arr[right - 1]) 
            right--;

        int ans = right;
        int left = 0;
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) 
        {
            while (right < arr.size() && arr[left] > arr[right]) 
                right++;
            ans = min(ans, right - left - 1);
            left++;
        }
        return ans;
    }
};