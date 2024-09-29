class Solution {
public:
    
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
                {
                    st.insert(word[j]);
                }
                else
                {
                    consonant++;
                }
                if(st.size() == 5 && consonant == k)
                    ans++;
            }
        }
        return ans;
    }
};