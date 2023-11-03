class Solution {
public:
    
//     Runtime: 5 ms, faster than 39.00% of C++ online submissions for Build an Array With Stack Operations.
// Memory Usage: 8.2 MB, less than 49.67% of C++ online submissions for Build an Array With Stack Operations.
    
    vector<string> buildArray(vector<int>& target, int n) {
         vector<string> res;
        string ph = "Push";
        string pp = "Pop";
        int num = 1;
        for(int i=0; i<target.size(); i++) {
            while(num!=target[i]) {
                num++;
                res.push_back("Push");
                res.push_back("Pop");
            }
            res.push_back("Push");
            num++;
        }
        return res;
    }
};