class Solution {
public:
    
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(auto i : candies)
            ans.push_back(i + extraCandies >= maxi ? 1 : 0);
        return ans;
    }
};


    
//     Runtime: 4 ms, faster than 61.53% of C++ online submissions for Kids With the Greatest Number of Candies.
// Memory Usage: 9 MB, less than 16.58% of C++ online submissions for Kids With the Greatest Number of Candies.
    
    
    // vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    //     int maxi = *max_element(candies.begin(), candies.end());
    //     vector<bool> ans;
    //     for(auto i : candies)
    //         i + extraCandies >= maxi ? ans.push_back(1) : ans.push_back(0);
    //     return ans;
//     }
// };