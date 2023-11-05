class Solution {
public:
    
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        for(auto i : left)
            ans = max(ans, i);
        for(auto i : right)
            ans = max(ans, n - i);
        return ans;
    }
};
    
//     Runtime: 17 ms, faster than 68.53% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
// Memory Usage: 23 MB, less than 76.29% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
    
//      int getLastMoment(int n, vector<int>& left, vector<int>& right) {
//         int ans = 0;
//         for (int num : left) {
//             ans = max(ans, num);
//         }
        
//         for (int num : right) {
//             ans = max(ans, n - num);
//         }
        
//         return ans;
//     }
// };