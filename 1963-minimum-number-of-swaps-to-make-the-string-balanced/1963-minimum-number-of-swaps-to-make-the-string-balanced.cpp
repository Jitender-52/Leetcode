class Solution {
public:
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
            {
                  opening++;
            }
        }
        return ans;
    }
};