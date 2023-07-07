class Solution {
public:
    
    int answer(string &s, char c, int k)
    {
        int n = s.length();
        int i = 0, j = 0;
        
        int count = 0, ans = 0;
        while(i < n)
        {
            if(s[i] == c)
            {
                count++;
                ans = max(ans, count);
            }
            else if(k > 0)
            {
                count++;
                k--;
                ans = max(ans, count);
            }
            else
            {
                while(j < i && k == 0)
                {
                    if(s[j] == c)
                    {
                        j++;
                    }
                    else
                    {
                        k++;
                        j++;
                    }
                    count--;
                }
            }
            i++;
        }
        return ans;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        // cout << answerKey.length() << endl;
        // return max(answer(answerKey, 'T', k), answer(answerKey, 'F', k));
        
        int n = answerKey.length();
        unordered_map<char,int> mp;
        
        for(int i = 0; i < k; i++)
            mp[answerKey[i]]++;
        
        int ans = k, j = 0; // my bad minimum of answer will be atleast k which is taken in 0 to k loop;
        for(int i = k; i < n; i++)
        {
            mp[answerKey[i]]++;
            while(min(mp['T'], mp['F']) > k)
            {
               mp[answerKey[j]]--;
               j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};