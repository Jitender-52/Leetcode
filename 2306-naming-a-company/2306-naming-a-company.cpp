class Solution {
public:
    
    
      long long distinctNames(vector<string>& ideas) {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for (auto& idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        
        // Calculate number of valid names from every pair of groups.
        long long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for (auto& ideaA : initialGroup[i]) {
                    if (initialGroup[j].count(ideaA)) {
                        numOfMutual++;
                    }
                }

                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
};
    
//     long long distinctNames(vector<string>& ideas) {
//         int n = ideas.size();
//         map<char,int> mp;
//         for(int i = 0; i < n; i++)
//         {
//             mp[ideas[i][0]]++;
//         }
        
//         map<string, set<char>> st;
//         for(int i = 0; i < n; i++)
//         {
//             st[ideas[i].substr(1)].insert(ideas[i][0]);
//         }
        
//         long long ans = 0;
//         // long long count = 0;
//         // for(auto i : st)
//         // {
//         //     count = 0;
//         //     set<char> s = i.second;
//         //     for(auto j : s)
//         //     {
//         //         for(auto k : s)
//         //         {
//         //             if(j == k)
//         //                 continue;
//         //             count += (mp[j] * mp[k]); 
//         //         }
//         //     }
//         // }
        
//         map<pair<char,char>,int> m;
        
//         for(auto i : st)
//         {
//             // cout << i.first << " ";
//             set<char> s = i.second;
//             for(auto j : s)
//             {
//                 cout << j << " ";
//                 for(auto k : s)
//                 {
//                     m[{j, k}] = -1;
//                     m[{k,j}] = -1;
//                 }
//             }
//             // cout << endl;
//         }
        
//         // char a = 'a';
//         // for(int i = 0; i < 26; i++)
//         // {
//         //     char c = 'a';
//         //     for(int j = 0; j < 26; j++)
//         //     {
//         //         if(m[{c, a}] == -1)
//         //             continue;
//         //         cout << a << " " << c << endl; 
//         //         ans += mp[c] * mp[a];
//         //         c++;
//         //     }
//         //     a++;
//         // }
        
//         for(auto i : mp)
//         {
//             for(auto j : mp)
//             {
//                 if(m[{i.first, j.first}] == -1)
//                     continue;
//                 // cout << i.first << " " << j.first << endl; 
//                 ans += i.second * j.second;
//             }
//         }
        
//         return ans;
//     }
// }; 