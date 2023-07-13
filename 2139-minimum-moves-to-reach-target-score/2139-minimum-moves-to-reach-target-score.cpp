class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        while(maxDoubles > 0 && target > 0)
        {
            if(target % 2 == 1)
            {
                target--;
            }
            else
            {
                target /= 2;
                maxDoubles--;
            }
            ans++;
        }
        ans += target;
        return ans-1;
    }
};