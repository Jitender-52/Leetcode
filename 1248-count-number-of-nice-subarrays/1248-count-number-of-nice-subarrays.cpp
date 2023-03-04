class Solution {
public:
    
            // Time complexity O(N)
            // Space complexity O(1)
    
            int numberOfSubarrays(vector<int>& nums, int k) {
                int n = nums.size();
                int ans = 0;
                int index = -1;
                int j = -1;
                int count = 0;
                for(int i = 0; i < n; i++)
                {
                    if(nums[i] % 2 == 1)
                    {
                        if(j == -1)
                        {
                            j = i;
                        }
                        count++;
                    }
                    if(count == k)
                    {
                        ans += j - index;
                    }
                    
                    if(count > k)
                    {
                        index = j;
                        j++;
                        while(j < n && nums[j] % 2 == 0)
                        {
                            j++;
                        }
                        count--;
                        if(count == k)
                        {
                            ans += j - index;
                        }
                    }
                }
                return ans;
            }
};


//     Runtime: 143 ms, faster than 77.92% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 69.5 MB, less than 55.37% of C++ online submissions for Count Number of Nice Subarrays.

        // Time complexity O(N)
        // Space complexity O(N)

    
//         int numberOfSubarrays(vector<int>& nums, int k) {
//             int n = nums.size();
//             int index = -1;
//             int i = 0;
//             int j = 0;
//             queue<int> q;
//             int ans = 0;
//             int count = 0;
//             for(int i = 0; i < n; i++)
//             {
//                 if(nums[i] % 2 == 1)
//                 {
//                     q.push(i);
//                     count++;
//                 }
//                 if(count == k)
//                 {
//                     // cout << i << endl;
//                     ans += q.front() - index;
//                 }
//                 if(count > k)
//                 {
//                     index = q.front();
//                     q.pop();
//                     count--;
//                     if(count == k)
//                     {
//                         ans += q.front() - index;
//                     }
//                 }
//             }
//             return ans;
//         }
// };
    
    
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int ans = 0;
//         int i = 0;
//         int j = 0;
//         int count = 0;
//         while(j < n)
//         {
//             if(count < k)
//             {
//                 if(i >= n)
//                     break;
//                 if(nums[i] % 2 == 1)
//                     count++;
//                 i++;
//             }   
//             else if(count > k)
//             {
//                 if(nums[j] % 2 == 1)
//                     count--;
//                 j++;
//             }
            
//             if(count == k)
//             {
//                 while(i <= j && count == k)
//                 {
//                     ans++;
//                     if(nums[j] % 2 == 1)
//                         count--;
//                     j++;
//                 }
//             }
//         }
//         return ans;
//     }
// };