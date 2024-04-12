class Solution {
public:
    
//     Runtime: 18 ms, faster than 11.08% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 22.3 MB, less than 80.10% of C++ online submissions for Trapping Rain Water.
    
    int trap(vector<int>& v) {
        int n = v.size();
        int l = 0, r = n-1, lh = 0, rh = 0, ans = 0;
        while(l <= r)
        {
            lh = max(lh, v[l]);
            rh = max(rh, v[r]);
            if(lh < rh)
                ans += lh - v[l++];
            else
                ans += rh - v[r--];
        }
        return ans;
    }
};

    
//     Runtime: 34 ms, faster than 5.09% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 20 MB, less than 96.48% of C++ online submissions for Trapping Rain Water.
    
    
//     int trap(vector<int>& v) {
//         int n = v.size();
//         int l = 0, r = n-1;
//         int lh = 0, rh = 0;
//         int ans = 0;
//         while(l <= r)
//         {
//             lh = max(lh, v[l]);
//             rh = max(rh, v[r]);
//             if(lh < rh)
//                 ans += lh - v[l++];
//             else
//                 ans += rh - v[r--];
//         }
//         return ans;
//     }
// };
    
//     int trap(vector<int>& v) {
//     int n = v.size();
//     int mini = INT_MIN;
//     int start = v[0];
//     int sum = 0;
//     int idx = 0;
//     int total = 0;
//     for (int i = 1; i < n; i++)
//     {
//         mini = max(mini, v[i]);
//         if (mini >= start)
//         {
//             total += start * (i - idx - 1) - sum;
//             // cout << total << endl;
//             idx = i;
//             sum = 0;
//             start = mini;
//             mini = -1;
//         }
//         else
//         {
//             sum += v[i];
//         }
//     }

//     start = v[n - 1];
//     mini = -1;
//     int p = idx;
//     idx = n - 1;
//     sum = 0;
//     for (int i = n - 2; i >= p; i--)
//     {
//         mini = max(mini, v[i]);
//         if (mini >= start)
//         {
//             total += start * (idx - i - 1) - sum;
//             // cout << total << endl;
//             idx = i;
//             sum = 0;
//             start = mini;
//             mini = -1;
//         }
//         else
//         {
//             sum += v[i];
//         }
//     }
//     return total;
//     }
// };