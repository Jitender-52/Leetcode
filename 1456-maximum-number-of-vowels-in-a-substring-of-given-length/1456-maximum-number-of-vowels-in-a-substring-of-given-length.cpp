class Solution {
public:
    
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        
        int ans = 0;
        int j = 0;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(isVowel(s[i]))
                count++;
            if(i - j + 1 > k)
            {
                if(isVowel(s[j]))
                    count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};