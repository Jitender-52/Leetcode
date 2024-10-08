class Solution {
public:
    
//     Runtime: 101 ms, faster than 70.15% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
// Memory Usage: 32.7 MB, less than 79.33% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
    
    int minSwaps(string s) {
        int ans = 0, opening = 0, closing = 0;
        for(auto i : s)
        {
            if(i == ']')
            {
                if(opening == 0)
                {
                    ans++;
                    opening++;
                }
                else
                    opening--;
            }
            else
                  opening++;
        }
        return ans;
    }
};