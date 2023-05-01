class Solution {
public:
    
        int minNumberOperations(vector<int>& target) {
            int n = target.size();
            int ans = target[0];
            for(int i = 1; i < n; i++)
            {
                ans += max(0, target[i] - target[i-1]);
            }
            return ans;
        }
};
    
    
//     int minNumberOperations(vector<int>& target) {
//         int n = target.size();
//         stack<int> st;
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             int maxi = 0;
//             while(!st.empty() && st.top() <= target[i])
//             {
//                 st.pop();
//             }
            
//             st.push(target[i]);
//         }
//     }
// };