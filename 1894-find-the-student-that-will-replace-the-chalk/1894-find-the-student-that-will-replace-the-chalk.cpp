class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = 0;
        for(auto i : chalk)
            sum += i;
        if(k >= sum)
            k %= sum;
        for(int i = 0; i < n; i++)
        {
            if(k < chalk[i])
                return i;
            k -= chalk[i];
        }
        return 0;
    }
};