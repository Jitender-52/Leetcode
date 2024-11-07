class Solution {
public:
    
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int i = 0; i < 30; i++)
        {
            int count = 0;
            for(auto j : candidates)
            {
                if(j & (1 << i))
                    count++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};
    
    
    // Read the question wrong, considered they are asking for subarray but its for combination.  That's why thought why it is in medium not in hard.
    // Will Work for subarray case
    // Nice code for subarray case for this question
    
//     int largestCombination(vector<int>& candidates) {
//         int n = candidates.size();
//         vector<vector<int>> v(n + 1, vector<int> (30, 0));
//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < 30; j++)
//             {
//                 if(candidates[i-1] & (1 << j))
//                     v[i][j] = v[i-1][j] + 1;
//                 else
//                     v[i][j] = v[i-1][j];
//             }
//         }
//         int ans = 0;
//         for(int i = 1; i < n; i++)
//         {
//             int low = i, high = n-1;
//             while(low <= high)
//             {
//                 int mid = (low + high) / 2;
//                 int count = 0;
//                 for(int j = 0; j < 30; j++)
//                     count += ((mid - i + 1) == (v[mid][j] - v[i-1][j]));
//                 if(count > 0)
//                     low = mid + 1;
//                 else
//                     high = mid - 1;
//             }
//             ans = max(ans, low - i + 1);
//         }
//         return ans;
//     }
// };