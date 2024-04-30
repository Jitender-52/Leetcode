class Solution {
public:
    
//     Runtime: 53 ms, faster than 68.86% of C++ online submissions for Number of Wonderful Substrings.
// Memory Usage: 16.5 MB, less than 64.67% of C++ online submissions for Number of Wonderful Substrings.
    
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024, 0); // 2^10 to store XOR values
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (auto ch : word) 
        {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor];

            for (int i = 0; i < 10; i++) 
                result += count[prefixXor ^ (1 << i)];
            count[prefixXor]++;
        }
        return result;
    }
};