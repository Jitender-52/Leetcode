class Solution {
public:
    
//     Runtime: 42 ms, faster than 52.39% of C++ online submissions for Sort Vowels in a String.
// Memory Usage: 12.3 MB, less than 82.05% of C++ online submissions for Sort Vowels in a String.
    
    bool isVowel(char a)
    {
        if(a == 'a' || a == 'e' || a == 'i' || a =='o' || a == 'u' || a == 'A' || a == 'E' || a == 'I' || a =='O' || a == 'U')
            return true;
        return false;
    }
    
    string sortVowels(string s) {
       int n = s.length();
        vector<char> v;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                v.push_back(s[i]);
            }
        }
        sort(v.begin(), v.end());
        int j = 0;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
            {
                s[i] = v[j];
                j++;
            }
        }
        return s;
    }
};