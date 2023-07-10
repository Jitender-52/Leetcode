class Solution {
public:
    
    map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    
    void dfs(string word, vector<string> &v)
    {
        // cout << word << endl;
        // if(mp[word] == 1)
        if(word == b)
        {
            reverse(v.begin(), v.end());
            ans.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }
        
        int sz = word.size();
        int steps = mp[word];
        for(int i = 0; i < sz; i++)
        {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                // cout << word << " " << mp[word] << endl;
                if(mp.find(word) != mp.end() && mp[word] + 1 == steps)
                {
                    v.push_back(word);
                    dfs(word, v);
                    v.pop_back();
                }
            }
            word[i] = original;
        }
    }
    
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            
            b = beginWord;
            
            set<string> st;
            for(auto i : wordList)
                st.insert(i);
            
            // for(auto i : st)
            //     cout << i << " ";
            
            queue<string> q;
            q.push(beginWord);
            mp[beginWord] = 1;
            st.erase(beginWord);
            int sz = beginWord.size();
            while(!q.empty())
            { 
                string word = q.front();
                q.pop();
                int steps = mp[word];
                if(word == endWord)
                    break;
                for(int i = 0; i < sz; i++)
                {
                    char original = word[i]; 
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        word[i] = c;
                        if(st.count(word))
                        {
                            // cout << word << endl;
                            q.push(word);
                            st.erase(word);
                            mp[word] = steps + 1;
                        }
                    }
                    word[i] = original;
                }
            }
            
            if(mp.find(endWord) != mp.end())
            {
                vector<string> v;
                v.push_back(endWord);
                dfs(endWord, v);
            }
            return ans;
        }
};


    
//     void dfs(string src, string startWord, map<string, int> &mp, vector<string> v, map<string, vector<string>> &adj, vector<vector<string>> &ans)
//     {
//         v.push_back(src);
//         if(src == startWord)
//         {
//             ans.push_back(v);
//             return;
//         }
        
//         for(auto i : adj[src])
//         {
//             if(i != src && mp[src] == mp[i] + 1)
//                 dfs(i, startWord, mp, v, adj, ans);
//         }
//     }
    
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         int n = wordList.size();
//         int m = beginWord.length();
        
//         // map<string, vector<string>> adj;
//         // for(int i = 0; i < n; i++)
//         // {
//         //     int count = 0;
//         //     for(int j = 0; i < m; i++)
//         //     {
//         //         if(wordList[i][j] != beginWord[j])
//         //             count++;
//         //     }
//         //     if(count == 1)
//         //         adj[beginWord].push_back(wordList[i]);
//         //     for(int j = i+1; j < n; j++)
//         //     {
//         //         count = 0;
//         //         for(int k = 0; k < m; k++)
//         //         {
//         //             if(wordList[i][k] != beginWord[k])
//         //                 count++;
//         //         }
//         //         if(count == 1)
//         //         {
//         //             adj[wordList[i]].push_back(wordList[j]);
//         //             adj[wordList[j]].push_back(wordList[i]);
//         //         }
//         //     }
//         // }
        
//         map<string, vector<string>> adj;
//         for(int i = 0; i < n; i++)
//         {
//             int a = 0;
//             for(int k = 0; k < m; k++)
//             {
//                 if(wordList[i][k] != beginWord[k])
//                     a++;
//             }
//             if(a == 1)
//             {
//                 adj[beginWord].push_back(wordList[i]);
//                 adj[wordList[i]].push_back(beginWord);
//             }
                
//             for(int j = i+1; j < n; j++)
//             {
//                 int count = 0;
//                 for(int k = 0; k < m; k++)
//                 {
//                     if(wordList[i][k] != wordList[j][k])
//                         count++;
//                 }
//                 if(count == 1)
//                 {
//                     adj[wordList[i]].push_back(wordList[j]);
//                     adj[wordList[j]].push_back(wordList[i]);
//                 }
//             }
//         }
        
//         map<string,int> mp;
//         queue<string> q;
//         q.push(beginWord);
        
//         int count = 1;
//         while(!q.empty())
//         {
//             int sz = q.size();
//             for(int i = 0; i < sz; i++)
//             {
//                 auto node = q.front();
//                 q.pop();
//                 mp[node] = count;
//                 cout << node << " ";
//                 for(auto i : adj[node])
//                 {
//                     // if(mp.find(i) == mp.end())
//                     string s = i;
//                     // if(mp[i] == 0)
//                     if(mp.find(i) == mp.end())
//                     {
//                         // cout << i << " " << mp[i] << endl;
//                         q.push(i);
//                     }
//                 }
//             }
//             cout << endl;
//             count++;
//         }
        
//         for(auto i : mp)
//         {
//             cout << i.first << " " << i.second << endl;
//         }
        
//         vector<vector<string>> ans;
//         vector<string> v;
        
//         dfs(endWord, beginWord, mp, v, adj, ans);
       
//         return ans;
//     }
// };
    
    
    
//     void dfs(string src, string startWord, map<string, int> &mp, vector<string> v, map<string, vector<string>> &adj, vector<vector<string>> &ans)
//     {
//         v.push_back(src);
//         if(src == startWord)
//         {
//             ans.push_back(v);
//             return;
//         }
        
//         for(auto i : adj[src])
//         {
//             if(i != src)
//                 dfs(i, startWord, mp, v, adj, ans);
//         }
//     }
    
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         int n = wordList.size();
//         int m = beginWord.length();
        
//         // map<string, vector<string>> adj;
//         // for(int i = 0; i < n; i++)
//         // {
//         //     int count = 0;
//         //     for(int j = 0; i < m; i++)
//         //     {
//         //         if(wordList[i][j] != beginWord[j])
//         //             count++;
//         //     }
//         //     if(count == 1)
//         //         adj[beginWord].push_back(wordList[i]);
//         //     for(int j = i+1; j < n; j++)
//         //     {
//         //         count = 0;
//         //         for(int k = 0; k < m; k++)
//         //         {
//         //             if(wordList[i][k] != beginWord[k])
//         //                 count++;
//         //         }
//         //         if(count == 1)
//         //         {
//         //             adj[wordList[i]].push_back(wordList[j]);
//         //             adj[wordList[j]].push_back(wordList[i]);
//         //         }
//         //     }
//         // }
        
//         map<string, vector<string>> adj;
//         for(int i = 0; i < n; i++)
//         {
//             int a = 0;
//             for(int k = 0; k < m; k++)
//             {
//                 if(wordList[i][k] != beginWord[k])
//                     a++;
//             }
//             if(a == 1)
//             {
//                 adj[beginWord].push_back(wordList[i]);
//                 adj[wordList[i]].push_back(beginWord);
//             }
                
//             for(int j = i+1; j < n; j++)
//             {
//                 int count = 0;
//                 for(int k = 0; k < m; k++)
//                 {
//                     if(wordList[i][k] != wordList[j][k])
//                         count++;
//                 }
//                 if(count == 1)
//                 {
//                     adj[wordList[i]].push_back(wordList[j]);
//                     adj[wordList[j]].push_back(wordList[i]);
//                 }
//             }
//         }
        
//         for(auto i : adj)
//         {
//             cout << i.first << " -> "; 
//             for(auto j : adj[i.first])
//                 cout << j << " ";
//             cout << endl;
//         }
        
//         map<string,int> mp;
//         queue<string> q;
//         q.push(beginWord);
        
//         int count = 1;
//         while(!q.empty())
//         {
//             int sz = q.size();
//             for(int i = 0; i < sz; i++)
//             {
//                 auto node = q.front();
//                 q.pop();
//                 mp[node] = count;
//                 for(auto i : adj[node])
//                 {
//                     // if(mp.find(i) == mp.end())
//                     string s = i;
//                     if(mp[i] == 0)
//                     {
//                         cout << i << " " << mp[i] << endl;
//                         q.push(i);
//                     }
//                 }
//             }
//             count++;
//         }
        
//         cout << endl << endl;
        
//         for(auto i : mp)
//             cout << i.first <<" " << i.second << endl;
//         cout << endl;
        
//         vector<vector<string>> ans;
        
//         // function<void(string, vector<string>)> dfs = [&](string src, vector<string> v)
//         // {
//         //     cout << src << " " << mp[src] << endl;
//         //     v.push_back(src);
//         //     if(src == beginWord)
//         //     {
//         //         ans.push_back(v);
//         //         return;
//         //     }
            
//         //     for(auto i : adj[src])
//         //     {
//         //         cout << i << " ";
//         //         // cout << mp[i] << " " << mp[src] << endl;
//         //         if(mp[i] + 1 == mp[src])  // coming from back i.e. endWord
//         //         {
//         //             dfs(i, v);
//         //         }
//         //     }
//         //     v.pop_back();
//         // };
        
//         vector<string> v;
//         // dfs(endWord, v);
        
//         dfs(endWord, beginWord, mp, v, adj, ans);
       
//         return ans;
//     }
// };