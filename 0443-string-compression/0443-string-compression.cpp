class Solution {
public:
    
    int compress(vector<char>& chars) {
        int n = chars.size();
        
        int count = 1;
        int ans = 0;
        int j = 0;
        int i;
        for(i = 1; i < n; i++)
        {
            // count++;
            if(chars[i] != chars[i-1])
            {
                if(count == 1)
                {
                    ans++;
                    chars[j] = chars[i-1];
                    j++;
                }
                else
                {
                    chars[j] = chars[i-1];
                    j++;
                    ans++;

                    string s = to_string(count);

                    for(int k = 0; k < s.length(); k++)
                    {
                        chars[j] = s[k];
                        j++;
                        ans++;
                    }
                    count = 1;
                }
            }
            else
            {
                count++;
            }
        }
        
        chars[j] = chars[i-1];
        j++;
        ans++;
        if(count > 1)
        {
            string s = to_string(count);
            for(int k = 0; k < s.length(); k++)
            {
                chars[j] = s[k];
                j++;
                ans++;
            }
        }
        return ans;
    }
};