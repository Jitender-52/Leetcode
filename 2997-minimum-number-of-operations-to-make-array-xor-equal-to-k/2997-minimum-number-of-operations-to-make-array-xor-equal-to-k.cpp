class Solution {
public:
    
//     Runtime: 107 ms, faster than 68.06% of C++ online submissions for Minimum Number of Operations to Make Array XOR Equal to K.
// Memory Usage: 91.5 MB, less than 25.13% of C++ online submissions for Minimum Number of Operations to Make Array XOR Equal to K.
    
    
        int minOperations(vector<int>& nums, int k) {
            int x = 0;
            for(auto i : nums)
                x ^= i;
            int ans = 0;
            for(int i = 0; i < 25; i++)
            {
                if(!(x & (1 << i)) != !(k & (1 << i)))
                    ans++;
            }
            return ans;
        }
};

    
//     int minOperations(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         for(int j = 0; j < 30; j++)
//         {
//             int x = (k & (1 << j)) != 0;
//             // cout << (1 << j) << endl;
//             int count = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 count += (nums[i] & (1 << j)) != 0;
//             }
//             // cout << count << " " << x << endl;
//             if(count % 2 != x)
//                 ans++;
//         }
//         return ans;
//     }
// };