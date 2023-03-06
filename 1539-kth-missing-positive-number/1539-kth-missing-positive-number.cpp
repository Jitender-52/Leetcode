class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 1;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] - s >= k)
            {
                return s + k - 1;
            }
            else
            {
                k -= arr[i] - s;
            }
            s = arr[i]+1;
        }
        return s + k - 1;
    }
};