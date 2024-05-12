class Solution {
public:
    int reachNumber(int target) {
        long long sum = 0, ans = 0;
        long long i = 1;
        target = abs(target);
        while(1)
        {
            ans++;
            sum += i;
            if(sum - target >= 0 && (sum - target) % 2 == 0)
                return ans;
            i++;
        }
        return ans;
    }
};