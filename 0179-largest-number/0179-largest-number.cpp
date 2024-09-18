class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Number.
// Memory Usage: 17.2 MB, less than 47.68% of C++ online submissions for Largest Number.
    
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto num : nums) 
            v.push_back(to_string(num));

        sort(v.begin(), v.end(), [&](string &a, string &b) 
        { 
            return a + b > b + a; 
        });
        if (v[0] == "0") 
            return "0";

        string ans = "";
        for (auto &i : v) 
            ans += i;
        return ans;
    }
};