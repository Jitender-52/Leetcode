class Solution {
public:
    
    void decToBinary(int n)
    {
        int binaryNum[32];

        int i = 0;
        while (n > 0) { 
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        for (int j = i - 1; j >= 0; j--)
            cout << binaryNum[j];
        cout << endl;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(auto i : nums)
            x ^= i;
        // cout << x << endl;
        x = x & -x;    //gives the last set bit
        // decToBinary(x);
        // decToBinary(-x);
        // cout << x << endl;
        
        vector<int> ans(2);
        for(auto i : nums)
        {
            if((x & i) == 0)
                ans[0] ^= i;
            else
                ans[1] ^= i;
        }
        return ans;
    }
};