class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for 2 Keys Keyboard.
// Memory Usage: 7.5 MB, less than 55.97% of C++ online submissions for 2 Keys Keyboard.
    
    int minSteps(int n) {
        int ans = 0;
        int a = 1;
        int i = 1;
        while(a < n)
        {
            if(n % a == 0)
            {
                i = a;
                a = 2 * i;
                ans += 2;
            }
            else
            {
                a += i;
                ans++;
            }
        }
        return ans;
    }
};