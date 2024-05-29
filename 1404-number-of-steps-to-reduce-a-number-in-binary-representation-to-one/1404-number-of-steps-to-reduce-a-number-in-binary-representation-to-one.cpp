class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.
// Memory Usage: 7.5 MB, less than 76.47% of C++ online submissions for Number of Steps to Reduce a Number in Binary Representation to One.

    
     int numSteps(string s) {
        int n = s.length();
        int ans = n - 1, carry = 0;

        for (int i = n - 1; i > 0; i--) {
            if (s[i] - '0' + carry == 1) {
                ans++;
                carry = 1;
            }
        }
        return ans + carry;
    }
};