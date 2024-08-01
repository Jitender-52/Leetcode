class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto s : details)
            ans += stoi(s.substr(11, 2)) > 60;
        return ans;
    }
};