class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [&](int a, int b){
            string s = to_string(a);
            string t = to_string(b);
            for(int i = 0; i < s.length(); i++)
                s[i] = (mapping[s[i] - '0'] + '0');
            for(int i = 0; i < t.length(); i++)
                t[i] = (mapping[t[i] - '0'] + '0');
            int x = stoi(s), y = stoi(t);
            return x < y;
        });
        return nums;
    }
};