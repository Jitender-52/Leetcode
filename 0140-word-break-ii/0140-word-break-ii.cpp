class Solution {
public:    
    
//     Runtime: 3 ms, faster than 34.00% of C++ online submissions for Word Break II.
// Memory Usage: 9.2 MB, less than 49.07% of C++ online submissions for Word Break II.
    
    vector<string> results;
    unordered_set<string> dict;

    void backTrack(const string& s, int start, string currentSentence) {
        if (start == s.length()) 
        {
            results.push_back(currentSentence.substr(0, currentSentence.length() - 1));
            return;
        }
        for (int i = start; i < s.length(); i++) 
        {
            if (dict.find(s.substr(start, i - start + 1)) != dict.end()) 
            {
                string temp = currentSentence + s.substr(start, i - start + 1) + " ";
                backTrack(s, i + 1, temp);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        results.clear();
        dict.clear();
        for (const string& word : wordDict) 
        {
            dict.insert(word);
        }
        backTrack(s, 0, "");
        return results;
    }
};
