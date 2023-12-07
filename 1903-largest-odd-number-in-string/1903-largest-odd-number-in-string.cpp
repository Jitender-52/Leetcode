class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        bool check = false;
        string ans = "";
        for(int i = n-1; i >= 0; i--)
        {
            if(check || (num[i] - '0') % 2)
            {
                ans += num[i];
                check = true;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};