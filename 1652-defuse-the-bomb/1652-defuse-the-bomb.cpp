class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defuse the Bomb.
// Memory Usage: 10.3 MB, less than 60.07% of C++ online submissions for Defuse the Bomb.
    
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result(code.size(), 0);
        if (k == 0) 
            return result;
        
        for (int i = 0; i < result.size(); i++)
        {
            if (k > 0) 
            {
                for (int j = i + 1; j < i + k + 1; j++) 
                {
                    result[i] += code[j % code.size()];
                }
            } 
            else 
            {
                for (int j = i - abs(k); j < i; j++) 
                {
                    result[i] += code[(j + code.size()) % code.size()];
                }
            }
        }
        return result;
    }
};