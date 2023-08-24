class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Text Justification.
// Memory Usage: 7.3 MB, less than 69.74% of C++ online submissions for Text Justification.
// Next challenges:
    
    vector<string> fullJustify(vector<string>& words, int L) {
        vector<string> res;
        for(int i = 0, k, l; i < words.size(); i += k) {
            for(k = l = 0; i + k < words.size() and l + words[i+k].size() <= L - k; k++) {
                l += words[i+k].size();
            }
            string tmp = words[i];
            for(int j = 0; j < k - 1; j++) {
                if(i + k >= words.size()) tmp += " ";
                else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i+j+1];
            }
            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};