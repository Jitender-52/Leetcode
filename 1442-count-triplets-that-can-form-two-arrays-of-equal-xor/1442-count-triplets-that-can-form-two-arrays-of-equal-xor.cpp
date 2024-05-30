class Solution {
public:
    
//     Runtime: 18 ms, faster than 22.49% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
// Memory Usage: 9 MB, less than 86.41% of C++ online submissions for Count Triplets That Can Form Two Arrays of Equal XOR.
    
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a = 0;
            for(int j = i + 1; j < n; j++)
            {
                int b = 0;
                a ^= arr[j-1];
                for(int k = j; k < n; k++)
                {
                    b ^= arr[k];
                    if(a == b)
                        ans++;
                }
            }
        }
        return ans;
    }
};