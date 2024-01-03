class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int ans = 0;
        int last = 0;
        for(int i = 0; i < bank[0].size(); i++)
            last += bank[0][i] == '1';
        for(int i = 1; i < n; i++)
        {
            auto s = bank[i];
            int count = 0;
            for(auto j : s)
                count += j == '1';
            if(count == 0)
                continue;
            ans += count * last;
            last = count;
        }
        return ans;
    }
};