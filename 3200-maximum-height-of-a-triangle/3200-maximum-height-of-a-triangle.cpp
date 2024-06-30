class Solution {
public:
    
    int solve(int first, int second)
    {
        int ans = 0;
        int a = 1, b = 2;
        int x = 1;
        while(1)
        {
            if(x)
            {
                if(first >= a)
                    first -= a;
                else
                    break;
            }
            else
            {
                if(second >= b)
                    second -= b;
                else
                    break;
            }
            ans++;
            if(x)
                a += 2;
            else
                b += 2;
            x ^= 1;
        }
        return ans;
    }
    
    int maxHeightOfTriangle(int red, int blue) {
        return max(solve(red, blue), solve(blue, red));
    }
};