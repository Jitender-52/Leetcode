class Solution {
public:
    
//     Runtime: 157 ms, faster than 18.18% of C++ online submissions for Count of Substrings Containing Every Vowel and K Consonants I.
// Memory Usage: 31 MB, less than 9.09% of C++ online submissions for Count of Substrings Containing Every Vowel and K Consonants I.
    
    bool isVowel(char c)
    {
        string s = "aeiou";
        for(auto i : s)
        {
            if(i == c)
                return true;
        }
        return false;
    }
    
    int countOfSubstrings(string word, int k) {
        int n = word.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            string s = "";
            set<int> st;
            int consonant = 0;
            for(int j= i; j < n; j++)
            {
                s += word[i];
                if(isVowel(word[j]))
                    st.insert(word[j]);
                else
                    consonant++;
                if(st.size() == 5 && consonant == k)
                    ans++;
            }
        }
        return ans;
    }
};