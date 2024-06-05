class Solution {
public:
    
//     Runtime: 22 ms, faster than 12.42% of C++ online submissions for Find Common Characters.
// Memory Usage: 15 MB, less than 15.01% of C++ online submissions for Find Common Characters.
    
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<map<char, int>> v(n);
        for(int i = 0; i < n; i++)
        {
            for(auto j : words[i])
                v[i][j]++;
        }
        
        auto mp1 = v[0];
        vector<string> ans;
        for(auto i : mp1)
        {
            for(int j = 0; j < i.second; j++)
            {
                bool check = true;
                for(int k = 0; k < n; k++)
                {
                    auto &mp = v[k];
                    if(mp.find(i.first) == mp.end())
                    {
                        check = false;
                        break;
                    }
                    else
                    {
                        mp[i.first]--;
                        if(mp[i.first] == 0)
                            mp.erase(i.first);
                    }
                }
                if(!check)
                    break;
                string s = "";
                s += i.first;
                ans.push_back(s);
            }
        }
        return ans;
    }
};