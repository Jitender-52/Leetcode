class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long long, int>> v(n);
        long long ans = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int sum = 0;
                long long x = (long long)nums[i] - (long long)nums[j];
                // cout << x << endl;
                if(v[j].find(x) != v[j].end())
                {
                    // cout << "HII" << endl;
                    sum = v[j][x];
                }
                // cout << j << " " << x << endl;
                v[i][x] += sum + 1;
                ans += sum;
            }
        }
        return ans;
    }
};