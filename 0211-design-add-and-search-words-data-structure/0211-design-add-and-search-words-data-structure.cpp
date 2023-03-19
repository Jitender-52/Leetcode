class WordDictionary {
public:
    
      
      vector<string> v;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int n = word.length();
        for(int i=0; i<v.size(); i++){
            // if(v[i].length() != word.length())
            if(v[i].length() != n)
                continue;
            
            bool check = true;
            for(int j = 0; j < n; j++)
            {
                if(word[j] == '.')
                {
                    continue;
                }
                if(v[i][j] != word[j])
                {
                    check = false;
                    break;
                }
            }
            if(check)
                return true;
        }
        return false;
    }
};
    
    
    
    
//     Runtime: 2777 ms, faster than 5.01% of C++ online submissions for Design Add and Search Words Data Structure.
// Memory Usage: 136.1 MB, less than 99.65% of C++ online submissions for Design Add and Search Words Data Structure.
    
//       vector<string> v;
//     WordDictionary() {
        
//     }
    
//     void addWord(string word) {
//         v.push_back(word);
//     }
    
//     bool search(string word) {
//         int count=0;
//         int n=word.size();
//         for(int i=0; i<v.size(); i++){
//             if(n==v[i].size()){
//                 for(int j=0; j<n; j++){
//                     if(v[i][j]==word[j]||word[j]=='.'){
//                         count++;
//                     }
//                     else{
//                         count=0;
//                         break;
//                     }
//                 }
//                 if(count==n) return true;
//             }
//         }
//         return false;
//     }
// };
    
    
    
//     unordered_set<string> st;
    
//     WordDictionary() {
        
//     }
    
//     void addWord(string word) {
//         st.insert(word);
//     }
    
//     bool search(string word) {
//         for(auto s : st)
//         {
//             if(word.length() != s.length())
//                 continue;
//             bool check = true;
//             for(int i = 0; i < s.length(); i++)
//             {
//                 if(word[i] == '.')
//                     continue;
//                 else if(s[i] != word[i])
//                 {
//                     check = false;
//                     break;
//                 }
//             }
//             if(check)
//                 return true;
//         }
//         return false;
//     }
// };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */