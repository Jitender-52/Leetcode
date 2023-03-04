class Solution {
public:
    
        int numberOfSubarrays(vector<int>& nums, int k) {
            int n = nums.size();
            int index = -1;
            int i = 0;
            int j = 0;
            queue<int> q;
            int ans = 0;
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] % 2 == 1)
                {
                    q.push(i);
                    count++;
                }
                if(count == k)
                {
                    // cout << i << endl;
                    ans += q.front() - index;
                }
                if(count > k)
                {
                    index = q.front();
                    q.pop();
                    count--;
                    if(count == k)
                    {
                        ans += q.front() - index;
                    }
                }
            }
            return ans;
        }
};
    
    
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