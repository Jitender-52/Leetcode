class Solution {
public:
    
//     Runtime: 98 ms, faster than 57.11% of C++ online submissions for Find Missing Observations.
// Memory Usage: 116.3 MB, less than 86.03% of C++ online submissions for Find Missing Observations.
    
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = 0;
        for (int i = 0; i < rolls.size(); i++) 
            sum = sum + rolls[i];
        
        int remainingSum = mean * (n + rolls.size()) - sum;
        if (remainingSum > 6 * n or remainingSum < n) 
            return {};
        
        int distributeMean = remainingSum / n;
        int mod = remainingSum % n;
        vector<int> nElements(n, distributeMean);
        for (int i = 0; i < mod; i++) 
            nElements[i]++;
        return nElements;
    }
};