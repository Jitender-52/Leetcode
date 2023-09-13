class Solution {
public:
    
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};
    
//     int candy(vector<int>& nums) {
//         int n = nums.size();
        
//         stack<int> st;
//         st.push(0);
//         int ans = 1;
//         for(int i = 1; i < n; i++)
//         {
//             if(st.empty())
//             {
//                 st.push(i);
//                 ans++;
//                 continue;
//             }
//             while(i < n && nums[i] > nums[i-1])
//             {
//                 ans += i - st.top() + 1;
//                 i++;
//             }
//             while(i < n && nums[i] == nums[i-1])
//             {
//                 ans++;
//                 st.push(i);
//                 i++;
//             }
//             while(i < n && nums[i] < nums[i-1])
//             {
//                 ans++;
//                 ans += i - st.top();
//                 i++;
//             }
//             i--;
//         }
//         return ans;
        
// //         int idx = 0;
// //         int mini = INT_MAX;
// //         for(int i = 0; i < n; i++)
// //         {
// //             if(ratings[i] < maxi)
// //             {
// //                 maxi = ratings[i];
// //                 idx = i;
// //             }
// //         }
        
// //         vector<int> v(n);
// //         v[idx] = 1;
// //         int i = idx-1, j = idx+1;
// //         while(i >= 0)
// //         {
// //             if(ratings[i] > )
// //         }
        
//     }
// };