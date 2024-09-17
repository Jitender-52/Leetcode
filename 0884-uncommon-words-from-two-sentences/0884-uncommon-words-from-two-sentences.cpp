class Solution {
public:
    
//     Runtime: 0 ms, faster than 100.00% of C++ online submissions for Uncommon Words from Two Sentences.
// Memory Usage: 9.1 MB, less than 28.22% of C++ online submissions for Uncommon Words from Two Sentences.

    
    map<string,int>mp;
    
    void stringstreeam(string s)
    {
        stringstream ss(s);
        string word;
        while(ss>>word) 
            mp[word]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        stringstreeam(s1);
        stringstreeam(s2);

        vector<string>ans;
        for(auto x : mp)
            if(x.second == 1) 
                ans.push_back(x.first);

        return ans;
    }
};