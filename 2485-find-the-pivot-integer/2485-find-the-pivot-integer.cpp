class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++)
            sum += i;
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            count += i;
            if(count == sum - count + i)
                return i;
        }
        return -1;
    }
};