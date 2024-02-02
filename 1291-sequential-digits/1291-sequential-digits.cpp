class Solution {
public:
    
//     Runtime: 3 ms, faster than 17.15% of C++ online submissions for Sequential Digits.
// Memory Usage: 7.5 MB, less than 8.37% of C++ online submissions for Sequential Digits.
    
    vector<int> ans;
    int l, r;
    void solve(int i, int num)
    {
        if(num >= l && num <= r)
            ans.push_back(num);
        if(num >= r || i > 9)
            return;
        num = num * 10 + i;
        solve(i+1, num);
    }
        
    vector<int> sequentialDigits(int low, int high) {
        l = low, r = high;
        for(int i = 1; i <= 9; i++)
            solve(i, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};