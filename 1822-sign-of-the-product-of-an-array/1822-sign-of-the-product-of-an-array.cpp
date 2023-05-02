class Solution {
public:
    
        int arraySign(vector<int>& nums) {
            int ans = 1;
            for(auto i : nums)
            {
                if(i == 0)
                    return 0;
                if(i < 0)
                    ans *= -1;
            }
            return ans;
        }
};
    
    
//     Runtime: 11 ms, faster than 16.81% of C++ online submissions for Sign of the Product of an Array.
// Memory Usage: 10.1 MB, less than 86.28% of C++ online submissions for Sign of the Product of an Array.
    
//     int arraySign(vector<int>& nums) {
//         int count = 0;
//         for(auto i : nums)
//         {
//             if(i == 0)
//                 return 0;
//             else if(i < 0)
//                 count++;
//         }
//         if(count % 2)
//             return -1;
//         return 1;
//     }
// };