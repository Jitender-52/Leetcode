class Solution {
public:
    
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        int lastConsonant = n;
        vector<int> nextConsonant(n);
        for(int i = n-1; i >= 0; i--)
        {
            nextConsonant[i] = lastConsonant;
            if(!isVowel(word[i]))
                lastConsonant = i;
        }
        
        map<char, int> vowels;
        long long ans = 0;
        int consonant = 0;
        int i = 0, j = 0;
        while(i < n)
        {
            if(isVowel(word[i]))
                vowels[word[i]]++;
            else
                consonant++;
            
            while(j <= i && consonant > k)
            {
                if(isVowel(word[j]))
                {
                    vowels[word[j]]--;
                    if(vowels[word[j]] == 0) 
                        vowels.erase(word[j]);
                }
                else
                    consonant--;
                j++;
            }
            while(j < i && vowels.size() == 5 && consonant == k)
            {
                ans += (nextConsonant[i] - i);
                if (isVowel(word[j])) 
                {
                    vowels[word[j]]--;
                    if(vowels[word[j]] == 0) 
                        vowels.erase(word[j]);
                } 
                else 
                    consonant--;
                j++;
            }
            i++;
        }
        return ans;
    }
};
    
//     Runtime: 157 ms, faster than 18.18% of C++ online submissions for Count of Substrings Containing Every Vowel and K Consonants I.
// Memory Usage: 31 MB, less than 9.09% of C++ online submissions for Count of Substrings Containing Every Vowel and K Consonants I.
    
//     bool isVowel(char c)
//     {
//         string s = "aeiou";
//         for(auto i : s)
//         {
//             if(i == c)
//                 return true;
//         }
//         return false;
//     }
    
//     int countOfSubstrings(string word, int k) {
//         int n = word.size();
//         int ans = 0;
//         for(int i = 0; i < n; i++)
//         {
//             string s = "";
//             set<int> st;
//             int consonant = 0;
//             for(int j= i; j < n; j++)
//             {
//                 s += word[i];
//                 if(isVowel(word[j]))
//                     st.insert(word[j]);
//                 else
//                     consonant++;
//                 if(st.size() == 5 && consonant == k)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// };