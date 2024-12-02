class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            bool check = true;
            while(i < n && sentence[i] != ' ')
            {
                if(j < m && sentence[i] == searchWord[j])
                    j++;
                else if(j < m)
                    check = false;
                i++;
            }
            if(j == m && check)
                return ans;
            ans++;
        }
        return -1;
    }
};