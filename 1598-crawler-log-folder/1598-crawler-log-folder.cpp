class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto i : logs)
        {
            if(i == "../")
                ans = max(ans - 1, 0);
            else if(i != "./")
                ans++;
        }
        return ans;
    }
};