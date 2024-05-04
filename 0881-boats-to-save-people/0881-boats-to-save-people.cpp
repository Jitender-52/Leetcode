class Solution {
public:
    
//     Runtime: 59 ms, faster than 47.36% of C++ online submissions for Boats to Save People.
// Memory Usage: 45.6 MB, less than 8.97% of C++ online submissions for Boats to Save People.
    
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        sort(people.begin(), people.end());
        while(i <= j)
        {
            if(people[i] + people[j] <= limit)
            {
                i++;
                j--;
            }
            else
            {
                j--;
            }
            ans++;
        }
        return ans;
    }
};
    
    
    // Binary Search
    
//     Runtime: 114 ms, faster than 5.33% of C++ online submissions for Boats to Save People.
// Memory Usage: 43.7 MB, less than 11.29% of C++ online submissions for Boats to Save People.

    
//     int numRescueBoats(vector<int>& people, int limit) {
//         int n = people.size();
//         int ans = 0;
//         sort(people.begin(), people.end());
//         vector<int> vis(n, 0);
//         for(int i = 0; i < n; i++)
//         {
//             if(vis[i])
//                 continue;
//             int low = i+1;
//             int high = n-1;
//             int idx = i;
//             while(low <= high)
//             {
//                 int mid = (low + high) / 2;
//                 if(people[mid] <= limit - people[i] && !vis[mid])
//                 {
//                     idx = mid;
//                     low = mid+1;
//                 }
//                 else
//                 {
//                     high = mid-1;
//                 }
//             }
//             vis[idx] = 1;
//             ans++;
//         }
        
//         return ans;
// //         int ans = 0;
// //         map<int,int> mp;   
// //         for(auto i : people)
// //         {
// //             mp[i]++;
// //         }
     
// //         for(auto i : mp)
// //         {
// //             auto it = mp.upper_bound(limit - i.first);
// //             it--;
// //             mp[i.first]--;
// //             if(it != mp.begin())
// //             {
// //                 mp[it->first]--;
// //                 if(mp[it->first] == 0)
// //                     mp.erase(it->first);
// //             }
// //             if(mp[i.first] == 0)
// //                 mp.erase(i.first);
// //             ans++;
// //         }
// //         return ans;
//     }
// };