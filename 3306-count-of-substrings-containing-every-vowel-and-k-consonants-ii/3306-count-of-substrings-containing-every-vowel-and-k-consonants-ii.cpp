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